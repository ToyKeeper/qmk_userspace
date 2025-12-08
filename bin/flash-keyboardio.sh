#!/bin/bash
MAKER=keyboardio
MODEL=model01
MAP=toykeeper
BRANCH=toykeeper-keymaps
BACKUP=$HOME/src/qmk/builds
set -e
echo "Put the keyboard into reflashing state now..."
sleep 3

cd ~/src/qmk/qmk_firmware/
source .venv/bin/activate
#git co $BRANCH
#make $MAKER/$MODEL:$MAP:flash
qmk flash -kb $MAKER/$MODEL -km $MAP
BUILD=$(basename $(/bin/ls -t  *.hex | head -1) .hex)
if [ -n "$BUILD" ]; then
  NOW=$(date +"%Y-%m-%d_%H%M")
  cp -v "$BUILD".hex "$BACKUP"/"$BUILD"."$NOW".hex
fi
echo -n 'Press Enter on the flashed keyboard:' ; read FOO
modmap
#sleep 1
#qwerty-dvorak.sh dvorak
