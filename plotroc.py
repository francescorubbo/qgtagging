from pylab import *
from utils import SetupATLAS
from sklearn.metrics import roc_curve
from dataprovider import DataProvider

SetupATLAS()
fig = plt.figure(figsize=(7, 5), dpi=100)

minpts = [50,400,1200]
maxpts = [100,500,1500]
linestyles = [':','--','-.']
qfile = '../data/testsyst/dijet.root'
gfile = '../data/testsyst/dijet.root'

var = 'ntrk500'

qdp = DataProvider(qfile,'qjet',[var])
gdp = DataProvider(gfile,'gjet',[var])

for minpt,maxpt,ls in zip(minpts,maxpts,linestyles):
    print minpt,maxpt

    #quarks
    qjets = qdp.getvar(var,ptmin=minpt,ptmax=maxpt)
    #gluons
    gjets = gdp.getvar(var,ptmin=minpt,ptmax=maxpt)

    target = np.concatenate( ( np.zeros(len(gjets)), np.ones(len(qjets)) ) )
    score = -1*np.concatenate( ( gjets, qjets ) )
    fpr,tpr,thres = roc_curve(target, score)
    plot(tpr, fpr, label='%d$<p_T<$%d GeV'%(minpt,maxpt),linestyle=ls)

from matplotlib.ticker import AutoMinorLocator, MultipleLocator
axes = plt.axes()
axes.xaxis.set_minor_locator(AutoMinorLocator())
axes.yaxis.set_minor_locator(AutoMinorLocator())

ylabel('Gluon Jet Efficiency', position=(0., 1.), va='top', ha='right')
xlabel('Quark Jet Efficiency', position=(1., 0.), va='bottom', ha='right')
axes.xaxis.set_label_coords(1., -0.20)
axes.yaxis.set_label_coords(-0.18, 1.)

plt.text(0.03, 0.95, "ATLAS",style='italic',weight='bold',fontsize = 18, ha='left', va='top', transform=axes.transAxes)
plt.text(0.21, 0.95, "Simulation Internal",fontsize = 18, ha='left', va='top', transform=axes.transAxes)
plt.text(0.03, 0.88, r"$\mathsf{\sqrt{s}}$ = 13 TeV",fontsize = 16, ha='left', va='top', transform=axes.transAxes)

plt.text(0.03, 0.81, r"Anti-k$_{\rm t}$ EM+JES R=0.4",fontsize = 16, ha='left', va='top', transform=axes.transAxes)
plt.text(0.03, 0.74, r"$|\eta|$<2.1",fontsize = 16, ha='left', va='top', transform=axes.transAxes)

ylim([0,1])
xlim([0,1])

legend(loc='center left')
#show()
savefig('plots/rocs.pdf')

