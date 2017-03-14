from root_numpy import root2rec
import numpy as np

class DataProvider:
    def __init__(self,filename,flav,vars):
        leaves = [flav+'_pt',flav+'_eta']
        for var in vars:
            if var not in ['pt','eta']: leaves += [flav+'reco_'+var]
        self.data = root2rec(filename,'tree',leaves)
        self.flav = flav

    def getvar(self,var,
               ptmin=80,ptmax=110,
               etamin=0.,etamax=2.1):
        vars = self.data[self.flav+'reco_'+var]
        pt = self.data[self.flav+'_pt']
        eta = self.data[self.flav+'_eta']
        return vars[(pt>ptmin) & (pt<ptmax) & (np.fabs(eta)>etamin) & (np.fabs(eta)<etamax)]
