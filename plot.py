from pylab import *
from utils import *
import numpy as np
from sklearn.metrics import roc_curve,auc
from sklearn.ensemble import AdaBoostClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.externals import joblib


minpts = [20,30,40,60,80,110]
maxpts = [30,40,60,80,110,160]
qfile = '../data/user.rubbo.341566.root'
gfile = '../data/user.rubbo.341565.root'

#vars = ['w','n','eec0','eec2','eec5','eec10']
vars = ['w','n','eec2','wtrk','ntrk']

for var in vars:
    pts = []
    aucs = []
    for minpt,maxpt in zip(minpts,maxpts):
        pts.append( minpt+(maxpt-minpt)/2 )
        qjets = getvar(var,'qjet',qfile,ptmin=minpt,ptmax=maxpt)
        gjets = getvar(var,'gjet',gfile,ptmin=minpt,ptmax=maxpt)
        aucs.append( 1.-getauc(qjets,gjets) )
    plot(pts,aucs,label=var)

bdt = joblib.load('bdt/bdt.pkl') 

bdtvars = ['w','n','eec2']

pts = []
aucs = []
for minpt,maxpt in zip(minpts,maxpts):
    pts.append( minpt+(maxpt-minpt)/2 )
    xx_qjets = np.vstack([
            getvar(var,'qjet',qfile,ptmin=minpt,ptmax=maxpt)
            for var in bdtvars]).T
    xx_gjets = np.vstack([
            getvar(var,'gjet',qfile,ptmin=minpt,ptmax=maxpt)
            for var in bdtvars]).T
    target = np.concatenate( ( np.zeros(len(xx_gjets)), np.ones(len(xx_qjets)) ) )
    X_test = np.concatenate( (xx_gjets,xx_qjets) )
    decisions = bdt.decision_function(X_test)
    aucs.append( roc_auc_score(target,decisions) )

plot(pts,aucs,label='bdt')


legend()
show()
