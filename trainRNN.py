from utils import *
from sklearn.cross_validation import train_test_split
from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation
from keras.layers import Embedding
from keras.layers import LSTM

from optparse import OptionParser
p = OptionParser()
p.add_option('--nMaxTrack', type ="string", default= '15', dest="nMaxTrack", help="Maximum number of tracks")
p.add_option('--nEpoch', type = "string", default = '10', dest = 'nEpoch', help = 'number of epochs ')

(o,a) = p.parse_args()
print o

minpt = 50
maxpt = 100

#[n_samples,n_tracks,n_features]

qfile = '/u/at/rubbo/nfs/qgtagging/data/user.rubbo.341566.root'
gfile = '/u/at/rubbo/nfs/qgtagging/data/user.rubbo.341565.root'
vars = ['pt']

max_len = int(o.nMaxTrack)
nb_epoch = int(o.nEpoch)

qjets = gettracks(vars,'qjet',qfile,ptmin=minpt,ptmax=maxpt)
gjets = gettracks(vars,'gjet',gfile,ptmin=minpt,ptmax=maxpt)

print 'qjets',qjets.shape
print 'gjets',gjets.shape
qweights = getweights('qjet',qfile,minpt,maxpt)
gweights = getweights('gjet',gfile,minpt,maxpt)
print 'qweights',qweights.shape
print 'gweights',gweights.shape

X = concatenate( (gjets, qjets) )
print X.shape
X = X[:,:max_len,:]
print X.shape
y = np.concatenate( ( np.zeros(gjets.shape[0]), np.ones(qjets.shape[0]) ) )
weights = np.concatenate( (gweights,qweights) )

print 'y',y.shape
print 'weights',weights.shape

X_train, X_test, y_train, y_test, w_train, w_test = train_test_split(X, y, weights, test_size=0.3)

model = Sequential()
model.add(LSTM(output_dim=128, activation='sigmoid', inner_activation='hard_sigmoid',
               input_shape=(max_len,len(vars))))
model.add(Dropout(0.5))
model.add(Dense(1))
model.add(Activation('sigmoid'))

model.compile(loss='binary_crossentropy',
              optimizer='rmsprop',
              metrics=['accuracy'])

model.fit(X_train, y_train, sample_weight=w_train, batch_size=16, nb_epoch=nb_epoch)
model.save_weights('model_ntrk'+o.nMaxTrack+'_nepoch'+o.nEpoch+'.h5')

score = model.evaluate(X_test, y_test, batch_size=16)
print 'score',score
