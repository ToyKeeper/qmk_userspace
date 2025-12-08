#!/bin/bash
MAKER=keychron
#MODEL=v1/v1_ansi_stm32l432_ec11
MODEL=v1/ansi_encoder
MAP=toykeeper
BRANCH=toykeeper-keychron
BACKUP=$HOME/src/qmk/builds
BINFILE=$(echo "$MAKER"_"$MODEL"_"$MAP".bin | sed 's|/|_|g')
set -e
echo "Put the keyboard into reflashing state now..."
sleep 3

cd ~/src/qmk/qmk_firmware/
source .venv/bin/activate
#cd ~/src/qmk/keychron/
#git co $BRANCH

TRIES=0
FAILED=1
while [ "$FAILED" != 0 ]; do
  sleep 2
  TRIES=$(($TRIES + 1))
  echo "Attempt $TRIES..."
  set +e
  #if make $MAKER/$MODEL:$MAP:flash ; then
  if qmk flash -kb $MAKER/$MODEL -km $MAP ; then
    FAILED=0
  fi
  set -e
done
echo "Flashing took $TRIES tries."

BUILD=$(basename $(/bin/ls -t  *.bin | head -1) .bin)
if [ -n "$BUILD" ]; then
  NOW=$(date +"%Y-%m-%d_%H%M")
  cp -v "$BUILD".bin "$BACKUP"/"$BUILD"."$NOW".bin
fi
echo -n 'Press Enter on the flashed keyboard:' ; read FOO
modmap
#sleep 1
#qwerty-dvorak.sh dvorak
