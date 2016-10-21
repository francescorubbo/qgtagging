import numpy as np
from keras.models import Sequential
from keras.layers import Dense
from sklearn.cross_validation import train_test_split
from sklearn.preprocessing import StandardScaler

samplesize = 10000

signal = np.stack([
        np.random.normal(13,5,samplesize),
        np.random.normal(0.1,0.3,samplesize),
        np.random.normal(0.24,0.05,samplesize),
        ])
bckg = np.stack([
        np.random.normal(19,5,samplesize),
        np.random.normal(0.15,0.3,samplesize),
        np.random.normal(0.29,0.04,samplesize),
        ])

signal = signal.T
bckg = bckg.T

X = np.concatenate( (signal,bckg) )
y = np.concatenate( (np.ones(signal.shape[0]),np.zeros(bckg.shape[0])) )

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

model = Sequential()
model.add( Dense(3, input_dim=(X_train.shape[1]), init='normal', activation='sigmoid') )
model.add( Dense(1, init='normal', activation='sigmoid') )
model.compile(loss='mean_squared_error', optimizer='sgd')

model.fit(X_train, y_train, batch_size=128, nb_epoch=10, validation_split=0.2)
score = model.evaluate(X_test, y_test, batch_size=32)
print 'score',score

#n
#q 13.0243452601 4.68262436439
#g 19.0480127466 5.15239054233
#w
#q 0.0970324989989 0.255386141003
#g 0.157087455012 0.32984423265
#eec2
#q 0.23823305648 0.0518236282979
#g 0.291473034025 0.0435235824777

#eta
#<0.30 0.268009396207
#<0.60 0.269589716499
#<0.90 0.272225239906
#<1.20 0.302150537634
#<1.50 0.343065693431
#<1.80 0.389678059674
#<2.10 0.469237628177


#from utils import *
#filename = '../data/dijet.root'
#
#var = 'eta'
#
#qjets = getvar(var,'qjet',filename,ptmin=80,ptmax=90)
#gjets = getvar(var,'gjet',filename,ptmin=80,ptmax=90)
#
#for x in np.linspace(0.,1.8,7):
#    nq = qjets[ ( np.fabs(qjets)<x+0.3 ) & ( np.fabs(qjets)>x ) ].shape[0]
#    ng = gjets[ ( np.fabs(gjets)<x+0.3 ) & ( np.fabs(gjets)>x ) ].shape[0]
#    print '<%1.2f'%(x+0.3),float(nq)/ng

