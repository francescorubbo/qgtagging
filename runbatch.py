import os

maxtracks = [10,20, 30, 40, 50]
nepochs = [10,20, 30, 40, 50]

for mt in maxtracks:
    for ne in nepochs:

        cmd = 'bsub -q atlas-t3 -W 80:00 -o $PWD/output/%(mt)s_%(ne)s $PWD/startup_anaconda.sh "python $PWD/trainRNN.py --nMaxTrack %(mt)s --nEpoch %(ne)s"'%{'mt':mt,'ne':ne}
        
        os.system(cmd)
