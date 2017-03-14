from pylab import *
from utils import *
from syst_dict import getsyst,applysyst
import ROOT as r
from array import array

SetupATLAS()

#minpts = [50,100]
#maxpts = [100,200]
minpts = [50,100,200,300,400,500,600,800,1000,1200]
maxpts = [100,200,300,400,500,600,800,1000,1200,1500]
dijetfilename = '../data/dijet.root'
vbffilename = '../data/vbfhbb.root'

var = 'ntrk'

ptbins = [50,100,200,300,400,500,600,800,1000,1200,1500]
nbins = 81
ntrkbins = np.linspace(-0.5,nbins-0.5,nbins+1).tolist()

fout = r.TFile('qgsyst_vbf.root','RECREATE')
h2dquark   = r.TH2D('h2dquark'  ,'h2dquark'  ,len(ptbins)-1,array('d',ptbins),nbins,array('d',ntrkbins))

for iptbin,(minpt,maxpt) in enumerate(zip(minpts,maxpts)):

    if minpt>300:
        for ibin in range(1,nbins+2):
            h2dquark.SetBinContent(iptbin+1,ibin,1.)
        continue

    prefix = 'vbf_%d_'%minpt
    hquark_dijet   = r.TH1D(prefix+'hquark_dijet'  ,prefix+'hquark_dijet'  ,nbins,array('d',ntrkbins))
    hquark_vbf     = r.TH1D(prefix+'hquark_vbf'    ,prefix+'hquark_vbf'  ,nbins,array('d',ntrkbins))

    qjets_dijet = getvar(var,'qjet',dijetfilename,reco=False,ptmin=minpt,ptmax=maxpt)
    qjets_vbf   = getvar(var,'qjet',vbffilename,reco=False,ptmin=minpt,ptmax=maxpt)
    for q in qjets_dijet: hquark_dijet.Fill(q)
    for q in qjets_vbf: hquark_vbf.Fill(q)
    norm_dijet = qjets_dijet.shape[0]
    norm_vbf = qjets_vbf.shape[0]
    hquark_dijet.Write()
    hquark_vbf.Write()
    for ibin in range(1,nbins+2):
        norm = float(norm_vbf)/norm_dijet
        val = hquark_vbf.GetBinContent(ibin)
        ratio = hquark_dijet.GetBinContent(ibin)/val if val>5 else 1.
        h2dquark.SetBinContent(iptbin+1,ibin,ratio*norm)
    
#set pT overflow to last bin value
for ibin in range(1,nbins+2):
    h2dquark.SetBinContent(h2dquark.GetNbinsX()+1,ibin,h2dquark.GetBinContent(h2dquark.GetNbinsX(),ibin))

h2dquark.Write()

#fout.Write()
