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

lossfunct = 'cross_entropy-lr0.01-shiftedpt'
output_dir = 'output/'

qfile = '/u/at/rubbo/nfs/qgtagging/data/user.rubbo.341566.root'
gfile = '/u/at/rubbo/nfs/qgtagging/data/user.rubbo.341565.root'

minpt = 50
maxpt = 100

max_len=10
vars = ['pt']

qjets = gettracks(vars,'qjet',qfile,train=0,ptmin=minpt,ptmax=maxpt) + 1.0
gjets = gettracks(vars,'gjet',gfile,train=0,ptmin=minpt,ptmax=maxpt) + 1.0
X = concatenate( (gjets, qjets) )
X = X[:,:max_len,:] 
y = np.concatenate( (np.zeros(len(gjets)), np.ones(len(qjets)) ) )


import matplotlib
matplotlib.use('pdf')
import matplotlib.pyplot as plt
from sklearn.metrics import auc
import os.path

_, axarr = plt.subplots(2, 1)


title = 'var-scan-%s-loss.pdf' % (lossfunct)
axarr[0].set_xlabel('nepochs')
axarr[0].set_ylabel('auc')

axarr[1].set_xlabel('False Positive')
axarr[1].set_ylabel('True Positive')

maxtracks = [5, 10, 20, 50]
nepochs = [1, 5, 10, 20]

for mt in maxtracks:
		scores = []
		aucs = []
		epochs = []
		for ne in nepochs:
			filename = output_dir + 'model_ntrk%(mt)d_nepochs%(ne)d'%{'mt':mt,'ne':ne}
			print filename
			if not os.path.isfile(filename):
					print 'not a file'
					continue
			epochs.append(ne)
			model = Sequential()
			model.add(Masking(mask_value=0.0, input_shape=(max_len, len(vars))))
			model.add(LSTM(output_dim=16, activation='sigmoid', inner_activation='hard_sigmoid'))
			model.add(Dropout(0.2))
			model.add(Dense(1))
			model.add(Activation('sigmoid'))
			model.compile(loss='binary_crossentropy',
              optimizer='rmsprop',
              metrics=['accuracy'])
			model.load_weights(filename)
			print 'Weights loaded'
			score = model.evaluate(X, y, batch_size=16)
			scores.append(score[1])
			print 'score %f', score
			proba = model.predict_proba(X, batch_size=16)
			fpr,tpr,thres = roc_curve(y, proba)	
			area =  auc(fpr, tpr)
			aucs.append(area)
			print 'plot being made'
			axarr[1].plot(fpr, tpr, linestyle='--', label='ntrk%(mt)d_nepoch%(ne)d'%{'mt':mt,'ne':ne})
			print 'done plotting auc ', area
		name = 'maxtracks: ' + str(mt)
		axarr[0].plot(epochs, aucs, linestyle='--', label=name)    


# Plotting versus truth
variables = ['n','neff']
for var in variables:
		qjets = -1.0 * getvar(var,'qjet',qfile,ptmin=minpt,ptmax=maxpt)
		gjets = -1.0 * getvar(var,'gjet',gfile,ptmin=minpt,ptmax=maxpt)
		target = np.concatenate( ( np.zeros(len(gjets)), np.ones(len(qjets)) ) )
		score = np.concatenate( ( gjets, qjets ) )
		fpr,tpr,thres = roc_curve(target,score)
		axarr[1].plot(fpr,tpr,label=var)


lgd1 = axarr[0].legend(loc='upper left', bbox_to_anchor=(1, 1.25))         
lgd2 = axarr[1].legend(loc='upper left', bbox_to_anchor=(1, 1.25))
plt.savefig(title,bbox_extra_artists=(lgd1, lgd2), bbox_inches='tight')
plt.close()


# Plot the validation error with epoch number 
#plt.xlabel('maxtracks')
#plt.ylabel('validation_error')
#for mt in maxtracks:
#		filename = 'model_ntrk%(mt)d_nepochs20_history.npy'%{'mt':mt}
#		val_loss = np.load(output_dir + filename)[()]['val_loss']
#		plt.plot(val_loss, label=filename)
#legend = plt.legend(loc='upper left', bbox_to_anchor=(1, 1.25))
#plt.savefig('val_error-vrs-epoch-%s.pdf' % (lossfunct), bbox_extra_artists=(legend,) , bbox_inches='tight')
#plt.close()
