import numpy as np

class Folding:
    def __init__(self,ptmin,ptmax):
        print 'begin initialize'
        file = '../data/dijet.root'
        truthvar = 'ntrk'
        recovar = 'ntrk500'
        qjets_t = getvar(truthvar,'qjet',file,reco=False,ptmin=ptmin,ptmax=ptmax)
        qjets_r = getvar(recovar,'qjet',file,reco=True,ptmin=ptmin,ptmax=ptmax)
        gjets_t = getvar(truthvar,'gjet',file,reco=False,ptmin=ptmin,ptmax=ptmax)
        gjets_r = getvar(recovar,'gjet',file,reco=True,ptmin=ptmin,ptmax=ptmax)
        truth = np.concatenate( (qjets_t[qjets_t>-1],gjets_t[gjets_t>-1]) )
        reco = np.concatenate( (qjets_r[qjets_t>-1],gjets_r[gjets_t>-1]) )
        self.recodict = dict( zip( range(0,31), [reco[truth==it] for it in range(0,31)] ))
        print 'done initialize'
        
    def fold(self,in_truth):
        print 'folding', len(in_truth)
        out_reco = [np.random.choice(self.recodict[it]) for it in in_truth]
        return np.array(out_reco)

from utils import *

minpt = 50
maxpt = 100
tvar = 'ntrk'
rvar = 'ntrk500'
qfile = '../data/user.rubbo.341566.root'
truth = getvar(tvar,'qjet',qfile,reco=False,ptmin=minpt,ptmax=maxpt)
reco = getvar(rvar,'qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)

folder = Folding(minpt,maxpt)

rfromt = folder.fold(truth)

from pylab import *
bins = np.linspace(-0.5,30.5,32)
#hist(truth,bins=bins,label='truth',alpha=0.3)
#hist(reco,bins=bins,label='reco',alpha=0.3)
hist(rfromt-reco,bins=bins,label='rfromt',alpha=0.3)

legend()

show()
