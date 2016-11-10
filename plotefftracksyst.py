from pylab import *
from utils import *
from syst_dict import getsyst,applysyst

SetupATLAS()

minpts = [50,100]
maxpts = [100,200]
#qfile = '../data/testsyst/JZ2W.root'
#gfile = '../data/testsyst/JZ2W.root'
qfile = '../data/testsyst/dijet.root'
gfile = '../data/testsyst/dijet.root'

var = 'ntrk500'
systs = ['trackeff','trackfake']
colors = ['g','r','b']

for systname,c in zip(systs,colors):
    print systname
    pts = []
    qeffs = []
    geffs = []
    qeffs_syst = []
    qeffs_symm = []
    geffs_syst = []
    geffs_symm = []
    for minpt,maxpt in zip(minpts,maxpts):
        print minpt,maxpt
        pts.append( minpt+(maxpt-minpt)/2 )
        
        qjets = getvar(var,'qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
        qjets_syst = getvar(var+systname,'qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
        qs = qjets[(qjets>=0) & (qjets_syst>=0)]
        qs_syst = qjets_syst[(qjets>0) & (qjets_syst>0)]
        gjets = getvar(var,'gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)
        gjets_syst = getvar(var+systname,'gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)
        gs = gjets[(gjets>=0) & (gjets_syst>=0)]
        gs_syst = gjets_syst[(gjets>=0) & (gjets_syst>=0)]

        wpcut = geteffcut(qs,wp=0.60)

        qeff = float(qs[qs<wpcut].shape[0])/qs.shape[0]
        geff = float(gs[gs<wpcut].shape[0])/gs.shape[0]
        qeffs.append( qeff )
        geffs.append( geff )

        qeff_syst = float(qs_syst[qs_syst<wpcut].shape[0])/qs_syst.shape[0]
        geff_syst = float(gs_syst[gs_syst<wpcut].shape[0])/gs_syst.shape[0]
        qeff_symm = 2*qeff-qeff_syst
        geff_symm = 2*geff-geff_syst
        
        qeffs_syst.append( qeff_syst )
        geffs_syst.append( geff_syst )
        qeffs_symm.append( qeff_symm )
        geffs_symm.append( geff_symm )
    
    plot(pts,qeffs,color=c,linestyle='--',marker='*')
    plot(pts,geffs,color=c,linestyle='--',marker='.')

    fill_between(pts,qeffs_syst,qeffs_symm,interpolate=True,
                 alpha=0.3,color=c,
                 label='syst: '+systname)
    fill_between(pts,geffs_syst,geffs_symm,interpolate=True,
                 alpha=0.3,color=c)

plot([],[],color='gray',linestyle='None',marker='*',label='Quark Jet')
plot([],[],color='gray',linestyle='None',marker='.',label='Gluon Jet')
ylabel('Efficiency')
xlabel('Jet $p_T$ [GeV]')


ylim([0.,0.95])
xlim([minpts[0],maxpts[-1]])

legend(loc='upper right')
#show()
savefig('plots/effvspTtracksyst')

