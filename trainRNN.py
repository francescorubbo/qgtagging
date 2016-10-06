from utils import *
from sklearn.cross_validation import train_test_split
from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation
from keras.layers import Embedding
from keras.layers import LSTM
from keras.layers import Masking

from optparse import OptionParser
from keras.callbacks import ModelCheckpoint
from keras.optimizers import RMSprop
p = OptionParser()
p.add_option('--nMaxTrack', type ="string", default= '15', dest="nMaxTrack", help="Maximum number of tracks")
p.add_option('--nEpoch', type = "string", default = '10', dest = 'nEpoch', help = 'number of epochs ')
#p.add_option('--trainFrac', type= "string", default = '0.3', dest = 'trainFrac', help='fraction of data to use for for training')

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
#trainFrac = float(o.trainFrac)

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
print 'maxlen', max_len

X_train, X_test, y_train, y_test, w_train, w_test = train_test_split(X, y, weights, test_size=0.3)
#num_train = int(len(X_train)*trainFrac)
#X_train = X_train[:num_train:, :, :]
#y_train = y_train[:num_train, :, :]
#w_train = w_train[:num_train, :, :]
print 'xtrain shape', X_train.shape

model = Sequential()
model.add(Masking(mask_value=0.0, input_shape=(max_len, len(vars))))
model.add(LSTM(output_dim=16, activation='sigmoid', inner_activation='hard_sigmoid'))
model.add(Dropout(0.2))
model.add(Dense(1))
model.add(Activation('sigmoid'))

optim = RMSprop(lr=0.01)
model.compile(loss='binary_crossentropy',
              optimizer=optim,
              metrics=['accuracy'])

save_prefix = 'model_ntrk'+o.nMaxTrack+'_nepochs'+o.nEpoch
#model.save_weights(save_prefix + '.h5') #'_trainFrac'+o.trainFrac+'.h5')
checkpointer = ModelCheckpoint(save_prefix, monitor='val_loss', save_weights_only=True, save_best_only=True)
hist = model.fit(X_train, y_train, sample_weight=w_train, batch_size=128, nb_epoch=nb_epoch, validation_split=0.2, callbacks=[checkpointer])
#model.save_weights(save_prefix + '.h5') #'_trainFrac'+o.trainFrac+'.h5')
np.save(save_prefix + '_history.npy', hist.history)

score = model.evaluate(X_test, y_test, batch_size=32)
print 'score',score
