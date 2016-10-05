from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation
from keras.layers import Embedding
from keras.layers import LSTM
from keras.layers import Masking
from sklearn.metrics import roc_curve

from utils import *

#from runbatch import maxtracks
#from runbatch import nepochs
import numpy as np

qfile = '/u/at/rubbo/nfs/qgtagging/data/user.rubbo.341566.root'
gfile = '/u/at/rubbo/nfs/qgtagging/data/user.rubbo.341565.root'

minpt = 50
maxpt = 100

max_len=10
vars = ['pt']

qjets = gettracks(vars,'qjet',qfile,train=0,ptmin=minpt,ptmax=maxpt)
gjets = gettracks(vars,'gjet',gfile,train=0,ptmin=minpt,ptmax=maxpt)
X = concatenate( (gjets, qjets) )
X = X[:,:max_len,:]
y = np.concatenate( (np.zeros(len(gjets)), np.ones(len(qjets)) ) )

y_temp = np.concatenate((np.ones(len(gjets)), np.zeros(len(qjets))))

import matplotlib
matplotlib.use('pdf')
import matplotlib.pyplot as plt
from sklearn.metrics import auc
import os.path

_, axarr = plt.subplots(2, 1)


title = 'var-scan.pdf'
axarr[0].set_xlabel('nepochs')
axarr[0].set_ylabel('auc')

axarr[1].set_xlabel('False Positive')
axarr[1].set_ylabel('True Positive')

maxtracks = [10, 20, 30, 50]
nepochs = [10, 20, 30]

for mt in maxtracks:
		scores = []
		aucs = []
		epochs = []
		for ne in nepochs:
			filename = 'output/model_ntrk%(mt)d_nepoch%(ne)d.h5'%{'mt':mt,'ne':ne}
			if not os.path.isfile(filename):
					print 'not a file'
					continue
			epochs.append(ne)
			model = Sequential()
			model.add(Masking(mask_value=0.0, input_shape=(max_len, len(vars))))
			model.add(LSTM(output_dim=128, activation='sigmoid', inner_activation='hard_sigmoid',
               input_shape=(max_len,len(vars))))
			model.add(Dropout(0.5))
			model.add(Dense(1))
			model.add(Activation('sigmoid'))
			model.compile(loss='binary_crossentropy',
              optimizer='rmsprop',
              metrics=['accuracy'])
			model.load_weights(filename)
			print 'Weights loaded'
			score = model.evaluate(X, y, batch_size=16)
			scores.append(score[1])
			proba = model.predict_proba(X, batch_size=16)
			fpr,tpr,thres = roc_curve(y_temp, proba)	
			area =  auc(fpr, tpr)
			aucs.append(area)
			print 'plot being made'
			axarr[1].plot(fpr, tpr, label='ntrk%(mt)d_nepoch%(ne)d.h5'%{'mt':mt,'ne':ne})
			print 'done plotting'
		name = 'maxtracks: ' + str(mt)
		axarr[0].plot(epochs, aucs, label=name)    


# Plotting versus truth
variables = ['n','neff']
for var in variables:
		qjets = getvar(var,'qjet',qfile,ptmin=minpt,ptmax=maxpt)
		gjets = getvar(var,'gjet',gfile,ptmin=minpt,ptmax=maxpt)
		target = np.concatenate( ( np.zeros(len(gjets)), np.ones(len(qjets)) ) )
		score = np.concatenate( ( gjets, qjets ) )
		fpr,tpr,thres = roc_curve(target,score)
		axarr[1].plot(fpr,tpr,linestyle='--',label=var)


lgd1 = axarr[0].legend(loc='upper left', bbox_to_anchor=(1, 1.25))         
lgd2 = axarr[1].legend(loc='upper left', bbox_to_anchor=(1, 1.25))
plt.savefig(title,bbox_extra_artists=(lgd1, lgd2), bbox_inches='tight')
plt.close()
