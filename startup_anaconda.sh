#!/bin/bash

/usr/local/bin/anaconda << EOF
. /u/at/$USER/.bash_profile
source activate researchpy
mkdir -p /tmp/$USER/
cd /tmp/$USER/
export THEANO_FLAGS="base_compiledir=${PWD}/BatchCompileDir/0/"
${1}
cp -r /tmp/$USER/*.h5 $PWD/output
cp -r /tmp/$USSER/*.npy $PWD/output
cd /tmp
rm -r /tmp/$USER
rm -r /tmp/.keras
EOF
