from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation
from keras.layers import Embedding
from keras.layers import LSTM

from utils import *

qfile = '../data/user.rubbo.341566.root'
gfile = '../data/user.rubbo.341565.root'

max_len=10
vars = ['pt']

model = Sequential()
model.add(LSTM(output_dim=128, activation='sigmoid', inner_activation='hard_sigmoid',
               input_shape=(max_len,len(vars))))
model.add(Dropout(0.5))
model.add(Dense(1))
model.add(Activation('sigmoid'))

model.compile(loss='binary_crossentropy',
              optimizer='rmsprop',
              metrics=['accuracy'])

model.load_weights('output/model_ntrk10_nepoch10.h5')



qjets = gettracks(vars,'qjet',qfile,train=0)
gjets = gettracks(vars,'gjet',qfile,train=0)
X = concatenate( (gjets, qjets) )
X = X[:,:max_len,:]
y = np.concatenate( ( np.zeros(len(gjets)), np.ones(len(qjets)) ) )


predicted = model.predict_proba(X,batch_size=16)

from sklearn.metrics import roc_curve

fpr,tpr,thres = roc_curve(y,predicted)

from pylab import *

plot(fpr,tpr,label='RNN')

show()
