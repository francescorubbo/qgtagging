from utils import *
from sklearn.cross_validation import train_test_split
from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation
from keras.layers import Embedding
from keras.layers import LSTM

#[n_samples,n_tracks,n_features]

qfile = '../data/user.rubbo.341566.root'
gfile = '../data/user.rubbo.341565.root'
vars = ['pt']

max_len = 20

qjets = gettracks(vars,'qjet',qfile)
gjets = gettracks(vars,'gjet',qfile)

print qjets.shape
print gjets.shape

X = concatenate( (gjets, qjets) )
print X.shape
X = X[:,:max_len,:]
y = np.concatenate( ( np.zeros(len(gjets)), np.ones(len(qjets)) ) )

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)

model = Sequential()
model.add(LSTM(output_dim=128, activation='sigmoid', inner_activation='hard_sigmoid',
               input_shape=(max_len,len(vars))))
model.add(Dropout(0.5))
model.add(Dense(1))
model.add(Activation('sigmoid'))

model.compile(loss='binary_crossentropy',
              optimizer='rmsprop',
              metrics=['accuracy'])

model.fit(X_train, y_train, batch_size=16, nb_epoch=10)
model.save_weights('model.h5')

score = model.evaluate(X_test, y_test, batch_size=16)
print 'score',score
