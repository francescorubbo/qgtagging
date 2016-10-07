from pylab import *
from utils import *

SetupATLAS()

minpts = [20,30,40,60,80,110,160,250]
maxpts = [30,40,60,80,110,160,250,400]
qfile = '../data/user.rubbo.341566.root'
gfile = '../data/user.rubbo.341565.root'

vars = ['w','ntrk','w','ntrk500']
recos = [False,False,True,True]
linestyles = ['b--','r--','b-','r-']

for var,reco,ls in zip(vars,recos,linestyles):
    pts = []
    aucs = []
    for minpt,maxpt in zip(minpts,maxpts):
        pts.append( minpt+(maxpt-minpt)/2 )
        qjets = getvar(var,'qjet',qfile,reco=reco,ptmin=minpt,ptmax=maxpt)
        gjets = getvar(var,'gjet',gfile,reco=reco,ptmin=minpt,ptmax=maxpt)
        aucs.append( 1.-getauc(qjets,gjets) )
    plot(pts,aucs,ls)

plot([],[],'b-',label='width')
plot([],[],'r-',label='$n_{track}$')
plot([],[],color='gray',linestyle='--',label='truth-level')
ylabel('AUC')
xlabel('Jet $p_T$ [GeV]')

legend(loc='lower right')
savefig('plotsHCW/AUCvspT')

