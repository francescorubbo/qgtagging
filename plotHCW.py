from pylab import *
from utils import *

SetupATLAS()

minpts = [20,50,100]
maxpts = [50,100,200]
colors = ['black','r','b']
qfile = '../data/user.rubbo.341566.root'
gfile = '../data/user.rubbo.341565.root'

var = 'ntrk500'

bins = np.linspace(0,30,31)
for minpt,maxpt in zip(minpts,maxpts):
    qjets = getvar(var,'qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
    gjets = getvar(var,'gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)
    hist(qjets,color='b',
         normed=True,histtype='step',bins=bins,
         label='Quark Jets')
    hist(gjets,color='r',
         normed=True,histtype='step',bins=bins,
         label='Gluon Jets')
    xlabel('$n_{track}$')
    ylabel('a.u.')
    legend(title='$%d<p_T<%d$ GeV'%(minpt,maxpt))
    savefig('plotsHCW/'+var+'_pt%d%d'%(minpt,maxpt))
    clf()

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
