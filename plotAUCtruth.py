from pylab import *
from utils import *
import numpy as np

SetupATLAS()

minpts = [20,30,40,60,80,110]
maxpts = [30,40,60,80,110,160]
qfile = '../data/user.rubbo.341566.root'
gfile = '../data/user.rubbo.341565.root'

vars = ['w','n','neff','eec2','wtrk','ntrk','nefftrk']

for var in vars:
    print 'plotting var ',var
    pts = []
    aucs = []
    for minpt,maxpt in zip(minpts,maxpts):
        pts.append( minpt+(maxpt-minpt)/2 )
        qjets = getvar(var,'qjet',qfile,ptmin=minpt,ptmax=maxpt)
        gjets = getvar(var,'gjet',gfile,ptmin=minpt,ptmax=maxpt)
        aucs.append( 1.-getauc(qjets,gjets) )
    plot(pts,aucs,label=var)

#axhline(0.5,linestyle='--',label='no discrimination')

ylabel('AUC')
xlabel('Jet $p_T$ [GeV]')

legend(loc='lower right')
ylim([0.65,0.85])
show()
#savefig('plotsHCW/truthAUCvspT_zoomed')


