from pylab import *
from utils import *
from syst_dict import getsyst,applysyst

SetupATLAS()

minpts = [50,100]
maxpts = [100,200]
qfile = '../data/testsyst/JZ2W.root'
gfile = '../data/testsyst/JZ2W.root'

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
        print minpt,maxpt
        pts.append( minpt+(maxpt-minpt)/2 )
        
        #quarks
        qjets = getvar(var,'qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
        qjets_wup = getvar(var+'w'+systname+'_up','qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
        qjets_wdown = getvar(var+'w'+systname+'_down','qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
        qs = qjets[(qjets_wup>0) & (qjets_wdown>0)]
        qs_up = qjets_wup[(qjets_wup>0) & (qjets_wdown>0)]
        qs_down = qjets_wdown[(qjets_wup>0) & (qjets_wdown>0)]
        
        #gluons
        gjets = getvar(var,'gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)
        gjets_wup = getvar(var+'w'+systname+'_up','gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)
        gjets_wdown = getvar(var+'w'+systname+'_down','gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)
        gs = gjets[(gjets_wup>0) & (gjets_wdown>0)]
        gs_up = gjets_wup[(gjets_wup>0) & (gjets_wdown>0)]
        gs_down = gjets_wdown[(gjets_wup>0) & (gjets_wdown>0)]

        wpcut = geteffcut(qs,wp=0.60)

        qeff = float(qs[qs<wpcut].shape[0])/qs.shape[0]
        geff = float(gs[gs<wpcut].shape[0])/gs.shape[0]
        qeffs.append( qeff )
        geffs.append( geff )

        qeff_up = float(qs_up[qs<wpcut].sum())/qs_up.sum()
        qeff_down = float(qs_down[qs<wpcut].sum())/qs_down.sum()
        geff_up = float(gs_up[gs<wpcut].sum())/gs_up.sum()
        geff_down = float(gs_down[gs<wpcut].sum())/gs_down.sum()

        qeffs_up.append( qeff_up )
        qeffs_down.append( qeff_down )
        geffs_up.append( geff_up )
        geffs_down.append( geff_down )
    
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
xlim([minpts[0],maxpts[-1]])

legend(loc='upper right')
#show()
savefig('plots/effvspTnchargedsyst')

