from root_numpy import root2rec
import numpy as np
from sklearn.metrics import roc_curve,auc,roc_auc_score

def getvar(var,flav,filename,
           reco=False,
           ptmin=80,ptmax=110,
           etamin=0.,etamax=2.1,train=0):

    varflav = flav
    if reco: varflav+='reco'

    leaves = [flav+'_pt',flav+'_eta']
    if var not in ['pt','eta']: leaves += [varflav+'_'+var]
    array = root2rec(filename,'tree',leaves)
    
    vars = array[varflav+'_'+var]
    pt = array[flav+'_pt']
    eta = array[flav+'_eta']
    
    return vars[(pt>ptmin) & (pt<ptmax) & (np.fabs(eta)>etamin) & (np.fabs(eta)<etamax)]

def getauc(qjets,gjets):
    target = np.concatenate( ( np.zeros(len(gjets)), np.ones(len(qjets)) ) )
    score = np.concatenate( ( gjets, qjets ) )
    roc_auc = roc_auc_score(target,score)
    return roc_auc

def geteffcut(jets,wp=0.5):
    varmax = jets.max()
    wpcut = 0.
    cuts = np.arange(0,varmax,float(varmax)/500)
    for cut in cuts:
        eff = float(jets[jets<cut].shape[0])/jets.shape[0]
        if eff>wp:
#            print 'eff',eff
            preveff = float(jets[jets<(cut-1)].shape[0])/jets.shape[0]
#            print 'preveff',preveff
            wpcut = cut if np.fabs(wp-eff)<np.fabs(wp-preveff) else (cut-1)
#            print 'cut/wpcut', cut, '/', wpcut
            break
    return wpcut
    
def getvars(vars,flav,filename,
            ptmin=20,ptmax=200,
            etamin=0.,etamax=2.1):

    leaves_train = [flav+'_'+var for var in vars]
    leaves = leaves_train+[flav+'_pt',flav+'_eta']
    array = root2rec(filename,'tree',leaves)
    
    xx = np.vstack([array[leave] for leave in leaves_train]).T[1::2]
    pt = array[flav+'_pt'][1::2]
    eta = array[flav+'_eta'][1::2]

    return xx[(pt>ptmin) & (pt<ptmax) & (np.fabs(eta)>etamin) & (np.fabs(eta)<etamax)]

import pandas as pd
def zerofill(input):
    df = pd.DataFrame(input)
    return df.fillna(0.).as_matrix()

def gettracks(vars,flav,filename,
              ptmin=20,ptmax=200,
              etamin=0.,etamax=2.1,train=1):

    leaves_train = [flav+'_trk'+var for var in vars]
    leaves = leaves_train+[flav+'_pt',flav+'_eta']
    array = root2rec(filename,'tree',leaves)
    
    xx = np.array([zerofill(array[leave].tolist()).T for leave in leaves_train]).T[train::2]
    pt = array[flav+'_pt'][train::2]
    eta = array[flav+'_eta'][train::2]

    return xx[(pt>ptmin) & (pt<ptmax) & (np.fabs(eta)>etamin) & (np.fabs(eta)<etamax)]

def concatenate(tocombine=[]):
    nmax = max([elem.shape[1] for elem in tocombine])
    items = [np.pad(elem, ((0,0),(0,nmax-elem.shape[1]),(0,0)), 
                    mode='constant', constant_values=0)
             for elem in tocombine]
    return np.concatenate( items )

from hep_ml.reweight import BinsReweighter
def getweights(flav,filename,ptmin,ptmax):
    pt = getvar('pt',flav,filename,ptmin=ptmin,ptmax=ptmax,train=1)
    flatdist = np.random.uniform(ptmin,ptmax,pt.shape[0])    

    reweighter = BinsReweighter()
    reweighter.fit(original=pt, target=flatdist)
    return reweighter.predict_weights(pt)

import rootpy
from rootpy.plotting.style import get_style, set_style
from matplotlib import rc
def SetupATLAS():
    rootpy.log.basic_config_colorized()
    #use latex for text
#    rc('text', usetex=True)
    # set the style
    style = get_style('ATLAS')
    style.SetEndErrorSize(3)
    set_style(style)
    set_style('ATLAS',mpl=True)
    rc('font',family='sans-serif',weight='medium',size=16)
    rc('legend',fontsize=16)
