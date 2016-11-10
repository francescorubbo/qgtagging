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
systname = 'jeteff'

bins = np.linspace(-0.5,30.5,32)
bincenters = (bins+0.5)[:-1]

for minpt,maxpt in zip(minpts,maxpts):

    #quarks
    qjets = getvar(var,'qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
    qjets_syst = getvar(var+systname,'qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
    hnom = np.histogram(qjets,bins,density=True)[0]
    hsyst = np.histogram(qjets_syst,bins,density=True)[0]
    hsymm = hnom+hnom-hsyst
    
    fill_between(bincenters,hsyst,hsymm,interpolate=True,
                 alpha=0.3,color='b',
                 label='Quark Jets')

    #gluons
    gjets = getvar(var,'gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)
    gjets_syst = getvar(var+systname,'gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)
    hnom = np.histogram(gjets,bins,density=True)[0]
    hsyst = np.histogram(gjets_syst,bins,density=True)[0]
    hsymm = hnom+hnom-hsyst

    fill_between(bincenters,hsyst,hsymm,interpolate=True,
                 alpha=0.3,color='r',
                 label='Gluon Jets')



    xlabel('$n_{track}$')
    ylabel('a.u.')
    legend(title='syst: '+systname+'\n$%d<p_T<%d$ GeV'%(minpt,maxpt))
    savefig('plotsHCW/syst_'+systname+'_pt%d%d'%(minpt,maxpt))
    clf()
