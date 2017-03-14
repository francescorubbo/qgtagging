from pylab import *
from utils import *
from dataprovider import DataProvider

SetupATLAS()

#minpts = [50,100]
#maxpts = [100,200]
minpts = [50,100,200,300,400,500,600,800,1000,1200]
maxpts = [100,200,300,400,500,600,800,1000,1200,1500]
colors = ['black','r','b']
qfile = '../data/testsyst/dijet.root'
gfile = '../data/testsyst/dijet.root'

var = 'ntrk500'
systname = 'trackeff'

bins = np.linspace(-0.5,30.5,32)
bincenters = (bins+0.5)[:-1]

vars = [var,var+systname]
qdp = DataProvider(qfile,'qjet',vars)
gdp = DataProvider(gfile,'gjet',vars)

for minpt,maxpt in zip(minpts,maxpts):

    #quarks
    qjets = qdp.getvar(var,ptmin=minpt,ptmax=maxpt)
    qjets_syst = qdp.getvar(var+systname,ptmin=minpt,ptmax=maxpt)
    hnom = np.histogram(qjets,bins,density=True)[0]
    hsyst = np.histogram(qjets_syst,bins,density=True)[0]
    hsymm = hnom+hnom-hsyst
    
    fill_between(bincenters,hsyst,hsymm,interpolate=True,
                 alpha=0.3,color='b',
                 label='Quark Jets')

    #gluons
    gjets = gdp.getvar(var,ptmin=minpt,ptmax=maxpt)
    gjets_syst = gdp.getvar(var+systname,ptmin=minpt,ptmax=maxpt)
    hnom = np.histogram(gjets,bins,density=True)[0]
    hsyst = np.histogram(gjets_syst,bins,density=True)[0]
    hsymm = hnom+hnom-hsyst

    fill_between(bincenters,hsyst,hsymm,interpolate=True,
                 alpha=0.3,color='r',
                 label='Gluon Jets')

    xlabel('$n_{track}$')
    ylabel('a.u.')
    legend(title='syst: '+systname+'\n$%d<p_T<%d$ GeV'%(minpt,maxpt))
    savefig('plots/syst_'+systname+'_pt%d%d'%(minpt,maxpt))
    clf()

