from pylab import *
from utils import *
from syst_dict import getsyst,applysystpoisson,applysyst
import ROOT as r
from array import array

SetupATLAS()

minpts = [50]
maxpts = [100]
#minpts = [50,100,200,300,400,500,600,800,1000,1200]
#maxpts = [100,200,300,400,500,600,800,1000,1200,1500]
filename = '../data/dijet.root'

var = 'ntrk'
systname = 'exp'

ptbins = [50,100,200,300,400,500,600,800,1000,1200,1500]
nbins = 81
ntrkbins = np.linspace(-0.5,nbins-0.5,nbins+1).tolist()

fout = r.TFile('qgsyst_'+systname+'.root','RECREATE')
h2dquark_up   = r.TH2D('h2dquark_up'  ,'h2dquark_up'  ,len(ptbins)-1,array('d',ptbins),nbins,array('d',ntrkbins))
h2dquark_down = r.TH2D('h2dquark_down','h2dquark_down',len(ptbins)-1,array('d',ptbins),nbins,array('d',ntrkbins))
h2dgluon_up   = r.TH2D('h2dgluon_up'  ,'h2dgluon_up'  ,len(ptbins)-1,array('d',ptbins),nbins,array('d',ntrkbins))
h2dgluon_down = r.TH2D('h2dgluon_down','h2dgluon_down',len(ptbins)-1,array('d',ptbins),nbins,array('d',ntrkbins))

for iptbin,(minpt,maxpt) in enumerate(zip(minpts,maxpts)):
    prefix = systname+'_%d_'%minpt
    hquark      = r.TH1D(prefix+'hquark'     ,prefix+'hquark'     ,nbins,array('d',ntrkbins))
    hquark_up   = r.TH1D(prefix+'hquark_up'  ,prefix+'hquark_up'  ,nbins,array('d',ntrkbins))
    hquark_down = r.TH1D(prefix+'hquark_down',prefix+'hquark_down',nbins,array('d',ntrkbins))
    hgluon      = r.TH1D(prefix+'hgluon'     ,prefix+'hgluon'     ,nbins,array('d',ntrkbins))
    hgluon_up   = r.TH1D(prefix+'hgluon_up'  ,prefix+'hgluon_up'  ,nbins,array('d',ntrkbins))
    hgluon_down = r.TH1D(prefix+'hgluon_down',prefix+'hgluon_down',nbins,array('d',ntrkbins))

    #quarks
    syst = getsyst('quark',maxpt,systname)
    systup = syst[0]
    systdown = syst[1]
    qjets = getvar(var,'qjet',filename,reco=False,ptmin=minpt,ptmax=maxpt)
    qjets_up = applysystpoisson(1.,systup,qjets)
    qjets_down = applysystpoisson(-1.,systdown,qjets)
#    qjets_up = applysyst(1.,systup,qjets)
#    qjets_down = applysyst(-1.,systdown,qjets)
    for q in qjets: hquark.Fill(q)
    for q in qjets_up: hquark_up.Fill(q)
    for q in qjets_down: hquark_down.Fill(q)
    hquark.Write()
    hquark_up.Write()
    hquark_down.Write()
    for ibin in range(1,nbins+2):
        val = hquark.GetBinContent(ibin)
        ratioup = hquark_up.GetBinContent(ibin)/val if val>5 else 1.
        ratiodown = hquark_down.GetBinContent(ibin)/val if val>5 else 1.
        h2dquark_up.SetBinContent(iptbin+1,ibin,ratioup)
        h2dquark_down.SetBinContent(iptbin+1,ibin,ratiodown)

    #gluons
    syst = getsyst('gluon',maxpt,systname)
    systup = syst[0]
    systdown = syst[1]
    gjets = getvar(var,'gjet',filename,reco=False,ptmin=minpt,ptmax=maxpt)
    gjets_up = applysystpoisson(1.,systup,gjets)
    gjets_down = applysystpoisson(-1.,systdown,gjets)
#    gjets_up = applysyst(1.,systup,gjets)
#    gjets_down = applysyst(-1.,systdown,gjets)
    for g in gjets: hgluon.Fill(g)
    for g in gjets_up: hgluon_up.Fill(g)
    for g in gjets_down: hgluon_down.Fill(g)
    #hgluon.Write()
    #hgluon_up.Write()
    #hgluon_down.Write()
    for ibin in range(1,nbins+2):
        val = hgluon.GetBinContent(ibin)
        ratioup = hgluon_up.GetBinContent(ibin)/val if val>5 else 1.
        ratiodown = hgluon_down.GetBinContent(ibin)/val if val>5 else 1.
        h2dgluon_up.SetBinContent(iptbin+1,ibin,ratioup)
        h2dgluon_down.SetBinContent(iptbin+1,ibin,ratiodown)
    
#set pT overflow to last bin value
for ibin in range(1,nbins+2):
    h2dquark_up.SetBinContent(h2dquark_up.GetNbinsX()+1,ibin,h2dquark_up.GetBinContent(h2dquark_up.GetNbinsX(),ibin))
    h2dquark_down.SetBinContent(h2dquark_down.GetNbinsX()+1,ibin,h2dquark_down.GetBinContent(h2dquark_down.GetNbinsX(),ibin))
    h2dgluon_up.SetBinContent(h2dgluon_up.GetNbinsX()+1,ibin,h2dgluon_up.GetBinContent(h2dgluon_up.GetNbinsX(),ibin))
    h2dgluon_down.SetBinContent(h2dgluon_down.GetNbinsX()+1,ibin,h2dgluon_down.GetBinContent(h2dgluon_down.GetNbinsX(),ibin))

h2dquark_up.Write()
h2dquark_down.Write()
h2dgluon_up.Write()
h2dgluon_down.Write()

#fout.Write()
