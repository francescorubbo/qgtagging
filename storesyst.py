from pylab import *
from utils import *
from syst_dict import getsyst,applysyst
import ROOT as r

SetupATLAS()

minpts = [200]
maxpts = [300]
#minpts = [50,100,200]
#maxpts = [100,200,300]
filename = '../data/dijet.root'

var = 'ntrk500'
systname = 'pdf'

bins = np.linspace(-0.5,30.5,32)
bincenters = (bins+0.5)[:-1]

#ptbins = [50,100,200,300,400,500,600,800,1000,1200,1500]
qntrkbins = {
    50: 15,
    100: 20,
    200: 25,
    300: 30,
    400: 30,
    500: 35,
    600: 40,
    800: 45,
    1000: 50,
    1200: 55,
    1500: 60
    }

gntrkbins = {
    50: 18,
    100: 25,
    200: 30,
    300: 35,
    400: 40,
    500: 45,
    600: 45,
    800: 50,
    1000: 60,
    1200: 65,
    1500: 70
    }

fout = r.TFile('test.root','RECREATE')

for minpt,maxpt in zip(minpts,maxpts):

    hquark      = r.TH1I('hquark'     ,'hquark'     ,qntrkbins[minpt],0,qntrkbins[minpt])
    hquark_up   = r.TH1I('hquark_up'  ,'hquark_up'  ,qntrkbins[minpt],0,qntrkbins[minpt])
    hquark_down = r.TH1I('hquark_down','hquark_down',qntrkbins[minpt],0,qntrkbins[minpt])
    hgluon      = r.TH1I('hgluon'     ,'hgluon'     ,gntrkbins[minpt],0,gntrkbins[minpt])
    hgluon_up   = r.TH1I('hgluon_up'  ,'hgluon_up'  ,gntrkbins[minpt],0,gntrkbins[minpt])
    hgluon_down = r.TH1I('hgluon_down','hgluon_down',gntrkbins[minpt],0,gntrkbins[minpt])

    #quarks
    syst = getsyst('quark',maxpt,systname)
    systup = syst[0]
    systdown = syst[1]
    qjets = getvar(var,'qjet',filename,reco=True,ptmin=minpt,ptmax=maxpt)
    qjets_up = applysyst(1.,systup,qjets)
    qjets_down = applysyst(-1.,systdown,qjets)
    for q in qjets: hquark.Fill(q)
    for q in qjets_up: hquark_up.Fill(q)
    for q in qjets_down: hquark_down.Fill(q)

    #gluons
    syst = getsyst('gluon',maxpt,systname)
    systup = syst[0]
    systdown = syst[1]
    gjets = getvar(var,'gjet',filename,reco=True,ptmin=minpt,ptmax=maxpt)
    gjets_systup = applysyst(1.,systup,gjets)
    gjets_systdown = applysyst(-1.,systdown,gjets)
    for q in qjets: hquark.Fill(q)
    for q in qjets_up: hquark_up.Fill(q)
    for q in qjets_down: hquark_down.Fill(q)

fout.Write()
