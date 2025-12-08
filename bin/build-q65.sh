#!/bin/bash
MAKER=keychron
#MODEL=q65/q65_ansi_stm32l432_ec11
MODEL=q65/ansi_encoder
MAP=toykeeper
BRANCH=toykeeper-keymaps
BINFILE=$(echo "$MAKER"_"$MODEL"_"$MAP".bin | sed 's|/|_|g')
#cd ~/src/qmk/keychron/
cd ~/src/qmk/qmk_firmware/
source .venv/bin/activate
#../toykeeper/sync.sh .
#git co $BRANCH
#rm quantum/version.h
qmk compile -kb $MAKER/$MODEL -km $MAP
#make $MAKER/$MODEL:$MAP
md5sum $BINFILE
ls -l $BINFILE
