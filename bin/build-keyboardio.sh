#!/bin/bash
MAKER=keyboardio
MODEL=model01
MAP=toykeeper
BRANCH=toykeeper-keymaps
BINFILE=$(echo "$MAKER"_"$MODEL"_"$MAP".hex | sed 's|/|_|g')
cd ~/src/qmk/qmk_firmware/
source .venv/bin/activate
#../toykeeper/sync.sh .
#git co $BRANCH
#rm quantum/version.h
qmk compile -kb $MAKER/$MODEL -km $MAP
#make $MAKER/$MODEL:$MAP
md5sum $BINFILE
ls -l $BINFILE
