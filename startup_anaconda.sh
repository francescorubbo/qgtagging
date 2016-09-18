#!/bin/bash

/usr/local/bin/anaconda << EOF
. /u/at/rubbo/.bash_profile
source activate virtualpy
mkdir -p /tmp/rubbo/
cd /tmp/rubbo/
export THEANO_FLAGS="base_compiledir=${PWD}/BatchCompileDir/0/"
${1}
cp -r /tmp/rubbo/*.h5 /u/at/rubbo/nfs/qgtagging/analysis/output/
cd /tmp
rm -r /tmp/rubbo
rm -r /tmp/.keras
EOF
