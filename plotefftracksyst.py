from pylab import *
from dataprovider import DataProvider
from utils import SetupATLAS,geteffcut

SetupATLAS()
fig = plt.figure(figsize=(7, 5), dpi=100)

minpts = [50,100,200,300,400,500,600,800,1000,1200]
maxpts = [100,200,300,400,500,600,800,1000,1200,1500]
#qfile = '../data/testsyst/JZ2W.root'
#gfile = '../data/testsyst/JZ2W.root'
qfile = '../data/testsyst/dijet.root'
gfile = '../data/testsyst/dijet.root'

var = 'ntrk500'
systs = ['trackeff','trackfake']
systnames = {'trackeff':'Track efficiency','trackfake':'Track fake rate'}
colors = ['g','r','b']

qdp = DataProvider(qfile,'qjet',[var]+[var+syst for syst in systs])
gdp = DataProvider(gfile,'gjet',[var]+[var+syst for syst in systs])

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
        
        qjets = qdp.getvar(var,ptmin=minpt,ptmax=maxpt)
        qjets_syst = qdp.getvar(var+systname,ptmin=minpt,ptmax=maxpt)
        qs = qjets[(qjets>=0) & (qjets_syst>=0)]
        qs_syst = qjets_syst[(qjets>0) & (qjets_syst>0)]
        gjets = gdp.getvar(var,ptmin=minpt,ptmax=maxpt)
        gjets_syst = gdp.getvar(var+systname,ptmin=minpt,ptmax=maxpt)
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
    
    plot(pts,qeffs,color=c,linestyle='--',marker='o',mfc='none')
    plot(pts,geffs,color=c,linestyle='--',marker='v',mfc='none')

    fill_between(pts,qeffs_syst,qeffs_symm,interpolate=True,
                 alpha=0.3,color=c,
                 label=systnames[systname])
    fill_between(pts,geffs_syst,geffs_symm,interpolate=True,
                 alpha=0.3,color=c)

plot([],[],color='gray',linestyle='None',marker='o',label='Quark Jet')
plot([],[],color='gray',linestyle='None',marker='v',label='Gluon Jet')

from matplotlib.ticker import AutoMinorLocator, MultipleLocator
axes = plt.axes()
axes.xaxis.set_minor_locator(AutoMinorLocator())
axes.yaxis.set_minor_locator(AutoMinorLocator())

ylabel('Efficiency', position=(0., 1.), va='top', ha='right')
xlabel('Jet $p_T$ [GeV]', position=(1., 0.), va='bottom', ha='right')
axes.xaxis.set_label_coords(1., -0.20)
axes.yaxis.set_label_coords(-0.18, 1.)

plt.text(0.03, 0.95, "ATLAS",style='italic',weight='bold',fontsize = 18, ha='left', va='top', transform=axes.transAxes)
plt.text(0.21, 0.95, "Simulation Internal",fontsize = 18, ha='left', va='top', transform=axes.transAxes)
plt.text(0.03, 0.88, r"$\mathsf{\sqrt{s}}$ = 13 TeV",fontsize = 16, ha='left', va='top', transform=axes.transAxes)

ylim([0.,1.1])
xlim([minpts[0],maxpts[-1]])

legend(loc='upper right')
#show()
savefig('plots/effvspTtracksyst')

