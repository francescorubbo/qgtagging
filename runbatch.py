import os

maxtracks = [5, 10, 20, 50]
nepochs = [1, 5, 10, 20]
#trainFracs = [0.1, 0.3,  0.7,  1.0]
for mt in maxtracks:
    for ne in nepochs:
			#for tf in trainFracs:
			cmd = 'bsub -q atlas-t3 -W 80:00 -o $PWD/output_noshift/%(mt)s_%(ne)s $PWD/startup_anaconda.sh "python $PWD/trainRNN.py --nMaxTrack %(mt)s --nEpoch %(ne)s"'%{'mt':mt,'ne':ne}
			os.system(cmd)

#cmd = 'bsub -q xlong -W 16:00 -o $PWD/output/%(mt)s_%(ne)s_%(tf)s $PWD/startup_anaconda.sh "python $PWD/trainRNN.py --nMaxTrack %(mt)s --nEpoch %(ne)s --trainFrac %(tf)s"'%{'mt':mt,'ne':ne, 'tf':tf}
