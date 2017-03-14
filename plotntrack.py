from pylab import *
from dataprovider import DataProvider
from utils import SetupATLAS,geteffcut

SetupATLAS()
fig = plt.figure(figsize=(7, 5), dpi=100)

minpts = [50,400,1200]
maxpts = [100,500,1500]
colors = ['black','r','b']
qfile = '../data/testsyst/dijet.root'
gfile = '../data/testsyst/dijet.root'

var = 'ntrk500'

qdp = DataProvider(qfile,'qjet',[var])
gdp = DataProvider(gfile,'gjet',[var])

bins = np.linspace(0,60,61)
for minpt,maxpt,col in zip(minpts,maxpts,colors):
    #quarks
    qjets = qdp.getvar(var,ptmin=minpt,ptmax=maxpt)
    #gluons
    gjets = gdp.getvar(var,ptmin=minpt,ptmax=maxpt)
    hist(qjets,color=col,
         normed=True,histtype='step',bins=bins,
         label='%d$<p_T<$%d GeV'%(minpt,maxpt))
    hist(gjets,color=col,linestyle='dashed',
         normed=True,histtype='step',bins=bins
         )

plot([],[],color='gray',label='Quark Jet')
plot([],[],color='gray',linestyle='dashed',label='Gluon Jet')

from matplotlib.ticker import AutoMinorLocator, MultipleLocator
axes = plt.axes()
axes.xaxis.set_minor_locator(AutoMinorLocator())
axes.yaxis.set_minor_locator(AutoMinorLocator())

xlabel('$n_{track}$', position=(1., 0.), va='bottom', ha='right')
ylabel('a.u.', position=(0., 1.), va='top', ha='right')
axes.xaxis.set_label_coords(1., -0.20)
axes.yaxis.set_label_coords(-0.18, 1.)

plt.text(0.03, 0.95, "ATLAS",style='italic',weight='bold',fontsize = 18, ha='left', va='top', transform=axes.transAxes)
plt.text(0.21, 0.95, "Simulation Internal",fontsize = 18, ha='left', va='top', transform=axes.transAxes)
plt.text(0.03, 0.88, r"$\mathsf{\sqrt{s}}$ = 13 TeV",fontsize = 16, ha='left', va='top', transform=axes.transAxes)

ylim([0.,0.2])

legend(loc='center right')
savefig('plots/ntrack')
clf()
