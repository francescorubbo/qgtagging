from pylab import *
from utils import *

SetupATLAS()

minpts = [50,100]
maxpts = [100,200]
colors = ['black','r','b']
qfile = '../data/testsyst/JZ2W.root'
gfile = '../data/testsyst/JZ2W.root'

var = 'ntrk500'
systname = 'exp'

bins = np.linspace(-0.5,30.5,32)
bincenters = (bins+0.5)[:-1]

for minpt,maxpt in zip(minpts,maxpts):

    #quarks
    qjets = getvar(var,'qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
    qjets_wup = getvar(var+'w'+systname+'_up','qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)
    qjets_wdown = getvar(var+'w'+systname+'_down','qjet',qfile,reco=True,ptmin=minpt,ptmax=maxpt)

    q_tmp = qjets[(qjets_wup>0) & (qjets_wdown>0)]
    qup_tmp = qjets_wup[(qjets_wup>0) & (qjets_wdown>0)]
    qdown_tmp = qjets_wdown[(qjets_wup>0) & (qjets_wdown>0)]
    
    hup = np.histogram(q_tmp,bins,weights=qup_tmp,density=True)[0]
    hdown = np.histogram(q_tmp,bins,weights=qdown_tmp,density=True)[0]
    
    fill_between(bincenters,hup,hdown,interpolate=True,
                 alpha=0.3,color='b',
                 label='Quark Jets')

    #gluons
    gjets = getvar(var,'gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)
    gjets_wup = getvar(var+'w'+systname+'_up','gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)
    gjets_wdown = getvar(var+'w'+systname+'_down','gjet',gfile,reco=True,ptmin=minpt,ptmax=maxpt)

    g_tmp = gjets[(gjets_wup>0) & (gjets_wdown>0)]
    gup_tmp = gjets_wup[(gjets_wup>0) & (gjets_wdown>0)]
    gdown_tmp = gjets_wdown[(gjets_wup>0) & (gjets_wdown>0)]

    hup = np.histogram(gjets,bins,weights=gjets_wup,density=True)[0]
    hdown = np.histogram(gjets,bins,weights=gjets_wdown,density=True)[0]
    
    fill_between(bincenters,hup,hdown,interpolate=True,
                 alpha=0.3,color='r',
                 label='Gluon Jets')

    xlabel('$n_{track}$')
    ylabel('a.u.')
    legend(title='syst: '+systname+'\n$%d<p_T<%d$ GeV'%(minpt,maxpt))
    savefig('plots/syst_'+systname+'_pt%d%d'%(minpt,maxpt))
    clf()

