from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation
from keras.layers import Embedding
from keras.layers import LSTM

from utils import *

qfile = '../data/user.rubbo.341566.root'
gfile = '../data/user.rubbo.341565.root'

minpt = 50
maxpt = 100

max_len=10
vars = ['pt']

qjets = gettracks(vars,'qjet',qfile,train=0,ptmin=minpt,ptmax=maxpt)
gjets = gettracks(vars,'gjet',gfile,train=0,ptmin=minpt,ptmax=maxpt)
X = concatenate( (gjets, qjets) )
X = X[:,:max_len,:]
y = np.concatenate( ( np.zeros(len(gjets)), np.ones(len(qjets)) ) )

model = Sequential()
model.add(LSTM(output_dim=128, activation='sigmoid', inner_activation='hard_sigmoid',
               input_shape=(max_len,len(vars))))
model.add(Dropout(0.5))
model.add(Dense(1))
model.add(Activation('sigmoid'))

model.compile(loss='binary_crossentropy',
              optimizer='rmsprop',
              metrics=['accuracy'])


from pylab import *

maxtracks = [10,20,50]
for mt in maxtracks:
    nepochs = [10,20,50]
    scores = []
    for ne in nepochs:
        model.load_weights('output/model_ntrk%(mt)d_nepoch%(ne)d.h5'%{'mt':mt,'ne':ne})

        score = model.evaluate(X, y, batch_size=16)
        print 'score',score
        scores.append(score[1])

    plot(nepochs,scores)    
show()
#predicted = model.predict_proba(X,batch_size=16)
#
#from sklearn.metrics import roc_curve
#fpr,tpr,thres = roc_curve(y,predicted)
#
#plot(fpr,tpr,label='RNN')
#
#show()
