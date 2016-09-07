from sklearn.ensemble import AdaBoostClassifier
from sklearn.tree import DecisionTreeClassifier
import numpy as np
from utils import *
from sklearn.externals import joblib


qfile = '../data/user.rubbo.341566.root'
gfile = '../data/user.rubbo.341565.root'
#vars = ['w','n','eec0','eec2','eec5','eec10']
vars = ['w','n','eec2']

qjets = getvars(vars,'qjet',qfile)
gjets = getvars(vars,'gjet',qfile)

X = np.concatenate( (gjets, qjets) )
y = np.concatenate( ( np.zeros(len(gjets)), np.ones(len(qjets)) ) )

bdt = AdaBoostClassifier(DecisionTreeClassifier(max_depth=1),
                         algorithm="SAMME",
                         n_estimators=200)

bdt.fit(X, y)
joblib.dump(bdt, 'bdt/bdt.pkl')
