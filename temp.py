import numpy as np
from keras.models import Sequential
from keras.layers import Masking, LSTM
from keras.layers import Activation, Dense, Dropout



max_len = 10
#start = [[1, 2, 3, 4, 5, 1,2 ,3, 4, 5], [1, 2, 3, 4, 5, 1, 3,2,4, 5], [1, 0, 0, 4, 5, 1, 2, 3, 4, 5], [1, 0,3, 0, 0, 0,0,0,0,8]]
#X_train = np.repeat(start, 250, axis=0)
X_train = np.random.randn(1000, max_len, 1)
y_train = np.concatenate((np.zeros(500), np.ones(500)))
y_train = y_train.reshape((1000, 1))
w_train = np.random.randn(1000)
#X_train = X_train.reshape(1000, 10, 1)
print X_train.shape
print y_train.shape
print w_train.shape
model = Sequential()
model.add(Masking(mask_value=0.0, input_shape=(max_len, 1)))
model.add(LSTM(output_dim=16, activation='sigmoid', inner_activation='hard_sigmoid'))
model.add(Dropout(0.2))
model.add(Dense(1))
model.add(Activation('sigmoid'))

model.compile(loss='binary_crossentropy',optimizer='rmsprop', metrics=['accuracy'])
hist = model.fit(X_train, y_train,sample_weight=w_train,  batch_size=128, nb_epoch=2, validation_split=0.2)
print hist.history


