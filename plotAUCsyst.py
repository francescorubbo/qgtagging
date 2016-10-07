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
    aucups = []
    aucdowns = []
    for minpt,maxpt in zip(minpts,maxpts):
        pts.append( minpt+(maxpt-minpt)/2 )
        
        (systup,systdown) = getsyst('quark',maxpt,systname)
        qjets = getvar(var,'qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
        qjets_systup = applysyst(1.,systup,qjets)
        qjets_systdown = applysyst(-1.,systdown,qjets)
        
        (systup,systdown) = getsyst('gluon',maxpt,systname)
        gjets = getvar(var,'gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)
        gjets_systup = applysyst(1.,systup,gjets)
        gjets_systdown = applysyst(-1.,systdown,gjets)
        
        aucups.append( 1.-getauc(qjets_systup,gjets_systup) )
        aucdowns.append( 1.-getauc(qjets_systdown,gjets_systdown) )
        
    fill_between(pts,aucups,aucdowns,interpolate=True,
                 alpha=0.3,color=c,
                 label='syst: '+systname)


ylabel('AUC')
xlabel('Jet $p_T$ [GeV]')

xlim([50,300])

legend(loc='lower right')
#show()
savefig('plotsHCW/AUCvspTsyst')

