from pylab import *
from utils import *

SetupATLAS()

minpts = [20,30,40,60,80,110,160,250]
maxpts = [30,40,60,80,110,160,250,400]
qfile = '../data/user.rubbo.341566.root'
gfile = '../data/user.rubbo.341565.root'

vars = ['w','ntrk500']
cuts = [0.094,8]
colors = ['b','r']

for var,cut,c in zip(vars,cuts,colors):
    pts = []
    qeffs = []
    geffs = []
    for minpt,maxpt in zip(minpts,maxpts):
        pts.append( minpt+(maxpt-minpt)/2 )
        qjets = getvar(var,'qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
        gjets = getvar(var,'gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)

        wpcut = geteffcut(qjets,wp=0.60)

        qeffs.append( float(qjets[qjets<wpcut].shape[0])/qjets.shape[0] )
        geffs.append( float(gjets[gjets<wpcut].shape[0])/gjets.shape[0] )
    
    plot(pts,qeffs,color=c,linestyle='None',marker='*')
    plot(pts,geffs,color=c,linestyle='None',marker='.')

plot([],[],'b-',label='width')
plot([],[],'r-',label='$n_{track}$')
plot([],[],color='gray',linestyle='None',marker='*',label='Quark Jet')
plot([],[],color='gray',linestyle='None',marker='.',label='Gluon Jet')
ylabel('eff.')
xlabel('Jet $p_T$ [GeV]')


ylim([0.,0.9])

legend(loc='upper right')
#show()
savefig('plotsHCW/effvspT')

