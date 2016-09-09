from root_numpy import root2rec
import numpy as np
from sklearn.metrics import roc_curve,auc,roc_auc_score

def getvar(var,flav,filename,
           reco=False,
           ptmin=80,ptmax=110,
           etamin=0.,etamax=2.1):

    varflav = flav
    if reco: varflav+='reco'

    leaves = [varflav+'_'+var,flav+'_pt',flav+'_eta']
    array = root2rec(filename,'tree',leaves)
    
    vars = array[varflav+'_'+var][::2]
    pt = array[flav+'_pt'][::2]
    eta = array[flav+'_eta'][::2]
    
    return vars[(pt>ptmin) & (pt<ptmax) & (np.fabs(eta)>etamin) & (np.fabs(eta)<etamax)]

def getauc(qjets,gjets):
    target = np.concatenate( ( np.zeros(len(gjets)), np.ones(len(qjets)) ) )
    score = np.concatenate( ( gjets, qjets ) )
    roc_auc = roc_auc_score(target,score)
    return roc_auc
    
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
              etamin=0.,etamax=2.1):

    leaves_train = [flav+'_trk'+var for var in vars]
    leaves = leaves_train+[flav+'_pt',flav+'_eta']
    array = root2rec(filename,'tree',leaves)
    
    xx = np.array([zerofill(array[leave].tolist()).T for leave in leaves_train]).T[1::2]
    pt = array[flav+'_pt'][1::2]
    eta = array[flav+'_eta'][1::2]

    return xx[(pt>ptmin) & (pt<ptmax) & (np.fabs(eta)>etamin) & (np.fabs(eta)<etamax)]

def concatenate(tocombine=[]):
    nmax = max([elem.shape[1] for elem in tocombine])
    items = [np.pad(elem, ((0,0),(0,nmax-elem.shape[1]),(0,0)), 
                    mode='constant', constant_values=0)
             for elem in tocombine]
    return np.concatenate( items )


import rootpy
from rootpy.plotting.style import get_style, set_style
from matplotlib import rc
def SetupATLAS():
    rootpy.log.basic_config_colorized()
    #use latex for text
    rc('text', usetex=True)
    # set the style
    style = get_style('ATLAS')
    style.SetEndErrorSize(3)
    set_style(style)
    set_style('ATLAS',mpl=True)
    rc('font',family='sans-serif',weight='medium',size=16)
    rc('legend',fontsize=16)