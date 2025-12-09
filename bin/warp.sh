#!/bin/sh
# Warp / teleport the mouse cursor between two locations in X11
# Copyright (C) 2025 Selene ToyKeeper
# SPDX-License-Identifier: GPL-3.0-or-later

XDO="xdotool"
# Recommended: mount a ramdisk in ~/ram/ and put the state file there
# (like `cd ; ln -s ../../run/user/$UID ram`)
STATEFILE="$HOME/.warp-location"
[ -d "$HOME/ram" ] && STATEFILE="$HOME/ram/.warp-location"


main () {
    loadpos
    savepos
    warpcursor
    showcursor
}

savepos () {
    "$XDO" getmouselocation --shell \
        | grep '^.=' \
        > "$STATEFILE"
}

loadpos () {
    eval $(cat "$STATEFILE")
}

warpcursor () {
    "$XDO" mousemove "$X" "$Y"
}

inpath () {
    type "$1" >/dev/null 2>&1
}

showcursor () {

    # https://github.com/arp242/find-cursor
    if inpath find-cursor ; then
        find-cursor \
            -o 4 --outline-color grey30 \
            -l 2 --color grey70 \
            --size 150 \
            --distance 30 \
            --wait 300 \
            --grow \
            &

    # standard "xeyes" tool from `apt install x11-apps`
    elif inpath xeyes ; then
        # figure out where to put the window
        # Center of the screen:
        #WID=320
        #HGT=150
        #XW=$( xwininfo -root | grep Width | awk '{ print $2 }' )
        #XH=$( xwininfo -root | grep Height | awk '{ print $2 }' )
        #LEFT=$(( ( $XW/2 ) - ( $WID/2 ) ))
        #TOP=$(( ( $XH/2 ) - ( $HGT/2 ) ))
        #GEOM="$WID"x"$HGT"+"$LEFT"+"$TOP"

        # Centered under the mouse cursor
        WID=100
        HGT=50
        LEFT=$(( ( $X ) - ( $WID/2 ) ))
        TOP=$(( ( $Y ) - ( $HGT/2 ) ))
        GEOM="$WID"x"$HGT"+"$LEFT"+"$TOP"

        # only allow one instance of xeyes at a time
        killall --quiet xeyes 2>&1 > /dev/null
        #echo xeyes -geometry $GEOM
        xeyes -geometry $GEOM &
        MYPROC=$!

        sleep 0.5

        # kill the process we spawned, if it's still running (but not any other
        # xeyes instances which may have started since then)
        if [ -e /proc/$MYPROC ]; then
            kill $MYPROC 2>&1 > /dev/null
        fi

    fi
}

main

