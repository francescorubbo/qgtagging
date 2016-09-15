import os

maxtracks = [10,20,50]
nepochs = [10,20,50]

for mt in maxtracks:
    for ne in nepochs:

        cmd = 'bsub -q atlas-t3 -W 80:00 -o /u/at/rubbo/nfs/qgtagging/analysis/output/%(mt)s_%(ne)s /u/at/rubbo/nfs/qgtagging/analysis/startup_anaconda.sh "python /u/at/rubbo/nfs/qgtagging/analysis/trainRNN.py --nMaxTrack %(mt)s --nEpoch %(ne)s"'%{'mt':mt,'ne':ne}
        
        os.system(cmd)
