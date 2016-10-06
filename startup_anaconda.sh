#!/bin/bash

/usr/local/bin/anaconda << EOF
. /u/at/$USER/.bash_profile
source activate researchpy
mkdir -p /tmp/$USER/
cd /tmp/$USER/

suffix="$(cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 32 | head -n 1)"
export THEANO_FLAGS="base_compiledir=${PWD}/BatchCompileDir/${suffix}/"
${1}
cp -r /tmp/$USER/model_ntrk*_nepochs* $PWD/output
cp -r /tmp/$USER/*.npy $PWD/output
cd /tmp
rm -r /tmp/$USER
rm -r /tmp/.keras
EOF
