syst_gluon = {
    100:    {
        'exp':(0.44,0.34),
        'me' :(0.04,0.04),
        'pdf':(0.01,0.01),
        },#50-100 GeV
    200:    {
        'exp':(0.29,0.24),
        'me' :(0.06,0.06),
        'pdf':(0.06,0.05),
        },#100-200 GeV
    300:    {
        'exp':(0.15,0.24),
        'me' :(0.05,0.05),
        'pdf':(0.11,0.10),
        }#200-300 GeV
    }
syst_quark = {
    100:    {
        'exp':(0.82,1.16),
        'me' :(0.06,0.06),
        'pdf':(0.02,0.02),
        },#50-100 GeV
    200:    {
        'exp':(0.36,0.41),
        'me' :(0.23,0.23),
        'pdf':(0.11,0.10),
        },#100-200 GeV
    300:    {
        'exp':(0.26,0.28),
        'me' :(0.19,0.19),
        'pdf':(0.17,0.16),
        }#200-300 GeV
    }
    
def getsyst(flav,ptmax,systname):
    if 'quark'==flav:
        return syst_quark[ptmax][systname]
    elif 'gluon'==flav:
        return syst_gluon[ptmax][systname]

import numpy as np
def applysyst(sign,syst,ntracks):
    return ntracks+sign*( int(syst)+(np.random.rand(len(ntracks))<(syst%1)) )
