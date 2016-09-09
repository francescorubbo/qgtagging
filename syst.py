from pylab import *
from utils import *
from syst_dict import getsyst,applysyst

SetupATLAS()

minpts = [50,100,200]
maxpts = [100,200,300]
colors = ['black','r','b']
qfile = '../data/user.rubbo.341566.root'
gfile = '../data/user.rubbo.341565.root'

var = 'ntrk500'
systname = 'pdf'

bins = np.linspace(-0.5,30.5,32)
bincenters = (bins+0.5)[:-1]

for minpt,maxpt in zip(minpts,maxpts):

    #quarks
    syst = getsyst('quark',maxpt,systname)
    systup = syst[0]
    systdown = syst[1]
    qjets = getvar(var,'qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
    qjets_systup = applysyst(1.,systup,qjets)
    qjets_systdown = applysyst(-1.,systdown,qjets)
    hup = np.histogram(qjets_systup,bins,density=True)[0]
    hdown = np.histogram(qjets_systdown,bins,density=True)[0]

    fill_between(bincenters,hup,hdown,interpolate=True,
                 alpha=0.3,color='b',
                 label='Quark Jets')

    #gluons
    syst = getsyst('gluon',maxpt,systname)
    systup = syst[0]
    systdown = syst[1]
    gjets = getvar(var,'gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)
    gjets_systup = applysyst(1.,systup,gjets)
    gjets_systdown = applysyst(-1.,systdown,gjets)
    hup = np.histogram(gjets_systup,bins,density=True)[0]
    hdown = np.histogram(gjets_systdown,bins,density=True)[0]

    fill_between(bincenters,hup,hdown,interpolate=True,
                 alpha=0.3,color='r',
                 label='Gluon Jets')



    xlabel('$n_{track}$')
    ylabel('a.u.')
    legend(title='syst: '+systname+'\n$%d<p_T<%d$ GeV'%(minpt,maxpt))
    savefig('plotsHCW/syst_'+systname+'_pt%d%d'%(minpt,maxpt))
    clf()

