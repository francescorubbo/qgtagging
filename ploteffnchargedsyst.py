from pylab import *
from dataprovider import DataProvider
from utils import SetupATLAS,geteffcut

SetupATLAS()
fig = plt.figure(figsize=(7, 5), dpi=100)

minpts = [50,100,200,300,400,500,600,800,1000,1200]
maxpts = [100,200,300,400,500,600,800,1000,1200,1500]
qfile = '../data/testsyst/dijet.root'
gfile = '../data/testsyst/dijet.root'

var = 'ntrk500'
systs = ['exp','me','pdf']
systnames = {'exp':'Total exp.','me':'ME','pdf':'PDF'}
colors = ['g','r','b']
hatches = ['','','']
linestyles = ['--','-.',':']

vars = [var]+[var+'w'+syst+'_'+updown for syst in systs for updown in ['up','down']]
qdp = DataProvider(qfile,'qjet',vars)
gdp = DataProvider(gfile,'gjet',vars)

for systname,c,h,ls in zip(systs,colors,hatches,linestyles):
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
        qjets = qdp.getvar(var,ptmin=minpt,ptmax=maxpt)
        qjets_wup = qdp.getvar(var+'w'+systname+'_up',ptmin=minpt,ptmax=maxpt)
        qjets_wdown = qdp.getvar(var+'w'+systname+'_down',ptmin=minpt,ptmax=maxpt)
        qs = qjets[(qjets_wup>0) & (qjets_wdown>0)]
        qs_up = qjets_wup[(qjets_wup>0) & (qjets_wdown>0)]
        qs_down = qjets_wdown[(qjets_wup>0) & (qjets_wdown>0)]
        
        #gluons
        gjets = gdp.getvar(var,ptmin=minpt,ptmax=maxpt)
        gjets_wup = gdp.getvar(var+'w'+systname+'_up',ptmin=minpt,ptmax=maxpt)
        gjets_wdown = gdp.getvar(var+'w'+systname+'_down',ptmin=minpt,ptmax=maxpt)
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
    
    plot(pts,qeffs,color=c,linestyle='None',marker='o',mfc='none')
    plot(pts,geffs,color=c,linestyle='None',marker='v',mfc='none')

    fill_between(pts,qeffs_up,qeffs_down,interpolate=True,
                 alpha=0.3,color=c,hatch=h,linestyle=ls,linewidth=2,
                 label=systnames[systname])
    fill_between(pts,geffs_up,geffs_down,interpolate=True,
                 alpha=0.3,color=c,hatch=h,linestyle=ls,linewidth=2)

plot([],[],color='gray',linestyle='None',marker='o',mfc='none',label='Quark Jet')
plot([],[],color='gray',linestyle='None',marker='v',mfc='none',label='Gluon Jet')

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
savefig('plots/effvspTnchargedsyst')

