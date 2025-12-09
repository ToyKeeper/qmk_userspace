ToyKeeper's Keyboardio Model-01 Layout
======================================

A butterfly-shaped split keyboard with a unique layout.

WARNING: This keymap is no longer maintained.  There are a few reasons why:

- My Model-01 has such bad key chatter that it's basically unusable, and QMK's
  debouncing algorithms aren't implemented for it.  It needs significant
  development effort to fix that, and it's unclear whether there's enough room
  left in ROM to add the relevant code.  The build says it has only 738 bytes
  free, which might not be enough to add proper debouncing.
- Last time I tried to flash new firmware, the flashing process didn't work and
  I haven't bothered to figure out why.
- They hardware design was barely tolerable even at its best, so it's not worth
  the effort to keep the firmware updated when I won't be typing on it anyway.

It's kept here for historical purposes only.

The last known working version is what is still installed on my keyboard.
Here's what I get when I plug it in and press the build info key:

`QMK 0.17.9-1732-g52d6c9 [keyboardio/model01:toykeeper], Build date 2022-11-18-07:09:13, Keymap: http://toykeeper.net/keyboard/qmk/tk-model01.png`


## At A Glance

This is the layout internally, showing all the functions for each key:
![TK Model01](https://toykeeper.net/keyboard/qmk/tk-keyboardio.png)

This layout diagram can be edited
[here](https://www.keyboard-layout-editor.com/#/gists/0b83353e391f27c7c19f82da0aecc56b).


## Core Features

Most of the features are shared by all my keymaps.  Check my
[user dir](../../../../../users/toykeeper)
for the details.

Everything below is specific to this particular model of hardware.


## Hardware-Specific Notes

Things which differ from other models:

  * This is a completely different layout than all my other keyboards.  Many
    things are moved around to fit the physical design.

  * Moon and Star are on the two palm keys.  Press both to get a third Fn
    layer, with less often used functions, like changing the RGB settings.

  * For most keys, it doesn't matter if the user presses Moon or Star, since
    their key mappings are almost identical.  This allows the user to press
    whichever one is ergonomically easier at the time.

  * Since 2 keys are missing from the right side of the keyboard, compared to a
    traditional layout, those 2 keys have been moved to the center columns.

  * The other 4 center-column keys are used for app launchers, macros, closing
    windows, paste, Insert, and Delete.

  * Since there are no arrow keys, arrows are provided on the left hand in home
    row position.  An extra set of mouse buttons is there too, to make it
    easier to hold a button down while dragging or scrolling with the mouse.

  * Pressing multiple modifier keys is difficult on this layout, so Alt is
    treated as a one-shot to make it easier to press at the same time as GUI.
    When Alt is active, the Space+Backspace keys light up.


## Known Issues

  * QMK's regular debouncing is not available with this keyboard.  It would
    need some pretty deep changes to make it compatible with QMK's normal
    mechanism.  So if you have bouncy switches like I do, it's going to
    double-trigger a lot and there's no solution yet.

  * I don't really know what to do with the bottom right key, so it's just
    End/Home.  It should probably be used for something better.

  * I often had difficulty remembering which hand had GUI and which had Alt, so
    I made it symmetrical.  This reduces Alt to a secondary function though,
    which may be inconvenient sometimes.

  * Space is tight on AVR MCUs, so several features are disabled compared to my
    other keymaps.

  * The keycaps are completely custom and cannot be rearranged or replaced with
    any standard sets.  So the legends are pretty much guaranteed to not match
    the keymap, unless you get blank caps, ancient glyphs, or use the
    manufacturer's keymap.

