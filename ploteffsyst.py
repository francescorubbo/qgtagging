from pylab import *
from utils import *
from syst_dict import getsyst,applysyst

SetupATLAS()

minpts = [50,100,200]
maxpts = [100,200,300]
qfile = '../data/user.rubbo.341566.root'
gfile = '../data/user.rubbo.341565.root'

var = 'ntrk500'
systs = ['exp','me','pdf']
colors = ['g','r','b']


for systname,c in zip(systs,colors):
    pts = []
    qeffs = []
    geffs = []
    qeffs_up = []
    qeffs_down = []
    geffs_up = []
    geffs_down = []
    for minpt,maxpt in zip(minpts,maxpts):
        pts.append( minpt+(maxpt-minpt)/2 )
        qjets = getvar(var,'qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
        gjets = getvar(var,'gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)
        
        wpcut = geteffcut(qjets,wp=0.60)

        qeffs.append( float(qjets[qjets<wpcut].shape[0])/qjets.shape[0] )
        geffs.append( float(gjets[gjets<wpcut].shape[0])/gjets.shape[0] )

        (systup,systdown) = getsyst('quark',maxpt,systname)
        qjets_up = applysyst(1.,systup,qjets)
        qjets_down = applysyst(-1.,systdown,qjets)
        
        (systup,systdown) = getsyst('gluon',maxpt,systname)
        gjets_up = applysyst(1.,systup,gjets)
        gjets_down = applysyst(-1.,systdown,gjets)

        qeffs_up.append( float(qjets_up[qjets_up<wpcut].shape[0])/qjets_up.shape[0] )
        qeffs_down.append( float(qjets_down[qjets_down<wpcut].shape[0])/qjets_down.shape[0] )
        geffs_up.append( float(gjets_up[gjets_up<wpcut].shape[0])/gjets_up.shape[0] )
        geffs_down.append( float(gjets_down[gjets_down<wpcut].shape[0])/gjets_down.shape[0] )
    
    plot(pts,qeffs,color=c,linestyle='--',marker='*')
    plot(pts,geffs,color=c,linestyle='--',marker='.')

    fill_between(pts,qeffs_up,qeffs_down,interpolate=True,
                 alpha=0.3,color=c,
                 label='syst: '+systname)
    fill_between(pts,geffs_up,geffs_down,interpolate=True,
                 alpha=0.3,color=c)

plot([],[],color='gray',linestyle='None',marker='*',label='Quark Jet')
plot([],[],color='gray',linestyle='None',marker='.',label='Gluon Jet')
ylabel('Efficiency')
xlabel('Jet $p_T$ [GeV]')


ylim([0.,0.95])
xlim([50.,300.])

legend(loc='upper right')
#show()
savefig('plotsHCW/effvspTsyst')

