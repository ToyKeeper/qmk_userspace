ToyKeeper's QMK Keymaps
=======================

This is the QMK userspace repo for my keymaps.

Most of the custom code is in my [user dir](users/toykeeper).


## Keyboards / Keymaps

Each layout diagram can be edited on [KLE](keyboard-layout-editor.com) using
the links provided in each keymap's readme file.

### Q65

[Keychron Q65](keyboards/keychron/q65/ansi_encoder/keymaps/toykeeper)

![TK Q65](https://toykeeper.net/keyboard/qmk/tk-q65.png)

### V1 / Q1

[Keychron V1](keyboards/keychron/v1/ansi_encoder/keymaps/toykeeper)

![TK V1](https://toykeeper.net/keyboard/qmk/tk-v1-q1.png)

### NK65

[NovelKeys NK65](keyboards/novelkeys/nk65/keymaps/toykeeper)

![TK NK65](https://toykeeper.net/keyboard/qmk/tk-nk65.png)

### Nuphy Air75 v2

This requires a
[modified fork of a vendor-specific fork](https://github.com/ToyKeeper/qmk_firmware/tree/tk-nuphy/keyboards/nuphy/air75_v2/ansi/keymaps/toykeeper)
of QMK v0.25 to build.

[Nuphy Air75 v2](keyboards/nuphy/air75_v2/ansi/keymaps/toykeeper)

![TK NK65](https://toykeeper.net/keyboard/qmk/tk-air75v2.png)

### Whitefox

[Whitefox](keyboards/input_club/whitefox/keymaps/toykeeper)

![TK Whitefox](https://toykeeper.net/keyboard/qmk/tk-whitefox.png)

### Keyboardio Model-01

(no longer maintained)

[Keyboardio Model-01](keyboards/keyboardio/model01/keymaps/toykeeper)

![TK Keyboardio](https://toykeeper.net/keyboard/qmk/tk-keyboardio.png)


## Concept

Some layouts are designed so the user can stay in home row position all the
time, and anything outside that area is discouraged or even eliminated
entirely.  This is not that type of layout.

Instead, these layouts are designed to facilitate multiple different hand
positions for different tasks.  The user's hands are expected to move around
sometimes, like to tap something in the corner of the keyboard, or roll over to
the side, or even to hold the keyboard by the edges and navigate using only a
few keys at the edge.  Or drop both hands to the corners for extended mouse
use, with one hand moving the cursor and the other hand clicking buttons.  Or
use a touchpad with one hand, while clicking buttons on the keyboard with the
other.  It's meant to be used at a desk, on the couch, in a lap, even standing
while holding the keyboard.  Sometimes 1-handed, sometimes 2-handed.  So some
functions are duplicated to make them accessible from multiple positions.

Many oft-used keys and combos are placed where they can be used with one hand,
like while resting one's chin on their hand, or holding food in one hand.  The
arrow cluster in particular is built for this type of use.  The layout is also
designed to be couch-friendly, like typing on one's lap while using a media PC
with only the keyboard, no mouse... or leaving the keyboard to the side and
reaching over to start videos or scroll a page or whatever.

Additionally some concessions are made to keep the layout from diverging too
much from a traditional keyboard, to make it easier to switch between a nice
QMK board and notebooks or legacy hardware.  And some things are moved around
to help make mappings more consistent across different hardware models.


## Features

*Note: VIA is not supported.*

These keymaps attempt to provide a similar experience across several different
hardware models.  Some of the features available are:

### Core layouts

Multiple layouts selectable with hotkeys or the dipswitch:

  - Qwerty
  - Dvorak
    - The user can choose to swap U and I keys on Dvorak layer, for a small
      optimization.  In English it seems that "I" gets typed far more often
      than "U", so this can help reduce finger strain a bit.  These modes may
      be referred to as "Dvorak" and "Dvoriuk".
  - Colemak-DH-TK (my variant of Colemak-DH)
  - Undvorak (allows typing Qwerty when the host is remapped to Dvorak)

Select a layout by holding Star (the "del" key in the upper right) and pressing
one of the lower-left keys (ctrl, win, alt, or lshift).  This saves that layer
to the current "save slot".  You can switch between save slots by toggling
a dip switch on the back of some keyboard models.

### Momentary "Fn" style layers

When held, these allow other keys to produce different events than the base
layer.

- Moon: Lower left corner of the keyboard.  This is the primary momentary
  layer, and it lights up in purple on most boards.

- Star: Upper right corner of the keyboard.  This is for secondary functions
  and right-hand combos, and it usually lights up in sort of a teal or
  aquamarine color.

- Third Fn layer when both palm keys are pressed.  (Keyboardio Model-01 only)

When any non-base layer is active, the keys defined in that layer light up in
a color-coded manner.  This is an easy way to see which layer(s) are active and
which keys are affected by it.

### Lockable layers

There are lockable or "sticky" layers for some things.  Tap a key to turn these
layers on or off.

- MouseLock: Turns the arrow cluster and nearby keys into mouse controls.
  Lights up in bubblegum pink.

- NumpadLock: Provides a numpad-like layer on keyboards which don't have
  a numpad.  Lights up in red.

- F-Lock: Toggles what the F1-F12 row does.  When activated, the F-row lights
  up in yellow and produces actual F1 to F12 keys.  Otherwise, it sends F plus
  10, like F13 to F22 and two launcher keys.  (only on boards with a F-row)

- Macro column modes.  (only on boards with a macro column)

### RGB

Responsive RGB lighting shows active layers and modifiers, color-coded for
clarity so they match the keymap diagrams.

RGB animation happens underneath the indicators.  The recommended mode is
`RGB_MATRIX_MULTISPLASH`.

The user can configure hue, saturation, value, effect type, and speed.

The background animation can also be turned off without disabling the
indicators for layers and modifiers.  Usually with `Star+Space`.

### Easier access to frequently-used keys

- The CapsLock key is Left Control.

- Backspace and Backslash are swapped by default for easier access, but can
  be un-swapped.  There is also a left-thumb Backspace.

- Star + the key next to it produces Shift+Insert, for pasting text.

- Moon is placed where it can be pressed with a knuckle or palm.  This makes it
  really easy to access the Moon layer by just rolling one hand a little to the
  side.

- The momentary layer keys are at the corners of the keyboard for easy access
  by feel.

### Tap-hold keys / tap-dance / multi-function keys

- Moon: Left mouse click when tapped, or activates the Moon layer when held.

- Star: Home when tapped, or activates the Star layer when held.

- LGUI: ("Windows key") Left mouse click when tapped, or LGUI when held.

- LAlt: Backspace when tapped, or LAlt when held.  Having Backspace immediately
  to the left of Space makes it feel very similar to a split space bar, and
  reduces strain on the pinky finger since there is usually no need to reach up
  to the regular backspace key.

- RCtl: Toggles the numpad layer when tapped, or RCtl when held.

- RAlt: Warp key when tapped, or RAlt when held.  See the section about the
  Warp key for more details.  On Whitefox, this key doesn't exist.

- RGUI: MouseLock when tapped, or RGUI when held.  On Whitefox, this key also
  works as RAlt: RAlt one-shot when tapped, MouseLock when tapped twice, or
  RGUI when held.

- Smart shift keys:
  - These enter `(` and `)` when tapped, or act as regular `Shift` keys when
    held.  This is known as "space cadet shift keys".
  - Additionally, holding both Shift keys for a moment activates CapsWord,
    which auto-shifts everything you type until the end of the next word.  It's
    like CapsLock, but more practical and less annoying.  Useful for
    programmers who often need to type things like `QMK_KEYWORD`.

- LCtl: ("CapsLock" key) Warp key when tapped, or LCtl when held.  See the
  section about the Warp key for more details.

- "Grave Escape" has the Escape key and Grave (`) / Tilde (~) on one key.
  - Tap normally for Esc
  - Shift for `~`
  - Left GUI for '`'
  - Moon produces a Shift-Esc event (handy for Chrome task manager)

### Dynamic macros

There are slots to record and play 2 different dynamic macros.

Press Moon plus qwerty A/S to record a macro into that slot, then press
whatever keys you want to record, then press the record key again to stop
recording.

Press Moon plus qwerty Z/X to play the macros.

On Keychron Q65, macro recording is moved to the macro column for one-tap
access to record and play macros.

### Space / Backspace / Delete

These keys are all pretty important and should be easy to access.  Space and
Backspace are both accessible with thumbs... right thumb for Space, or left
thumb (on LAlt) for Backspace.  Additionally, Moon+Space does a forward Delete.

For compatibility, the regular Backspace key also works, and holding Moon or
Star with it causes a forward Delete.

To hold the thumb Backspace key, tap it once then press it again and hold it.

This isn't quite as good as having a real split spacebar, but it's about as
close as you can get on a traditional physical layout.

### Mouse keys

Easy access to mouse keys, for people who don't have a mouse nearby (or who
simply don't want to use a mouse).

Mouse keys can be locked for single-finger access, and they glow while locked.

Uses the new "inertia" mode for more natural motion.  I'm biased since I wrote
it, but I think it makes MouseKeys much more usable and I often go entire days
without touching an actual mouse.

Mouse keys in this layout are designed to be used in 3 different hand
positions:

- Left corner clicks: Includes single-tap access for left click.  Also includes
  chords for full left, middle, and right clicks.  Left and right click are
  along the bottom row with Moon+LGUI and Moon+LAlt, and middle click is on
  Moon+LShift.  The middle click is here to make it easy to paste text with the
  mouse.

- Right corner mousing: Tap MouseLock (or Hold Moon) and press the arrow keys
  and other nearby keys to control the mouse.

- 2-handed full set in home position: Hold Moon with the left hand, and the
  right hand's home row position has a full set of mouse keys.  This includes
  cursor motion, 4-way scrolling, all 3 clicks, and Warp.

- Right-hand paste: Roll from Star to the next key to generate a Shift+Insert
  event.  This is the "paste" function in most Linux programs.  Between
  Star+Ins and Moon+LShift, there is an easy way to paste with either hand.  No
  explicit "copy" command is needed, because in Linux, simply selecting text
  will automatically copy it to the clipboard in most cases.

- Knob scrolling: On boards with a knob, turn the knob to send mousewheel
  scroll events.

### Mouse Warp

This requires support from the host OS.  The keyboard simply sends F23 for the
Warp function, and it's up to the host to do something useful with it.

When implemented, it's really handy.  It's like having two mouse cursors, and
a key to switch between them.  It works particularly well when you have "focus
follows mouse" enabled in your desktop environment.

The included [warp.sh](bin/warp.sh) script shows one way to implement this
feature, using xdotool in X11.  It also needs `find-cursor` or at least `xeyes`
in order to show the cursor location after warping.

But the way I do it is a bit of lisp code in my Sawfish window manager, and
a short shell script:

```lisp
(defvar warp-pos (query-pointer)
             "The last position the pointer was warped from")

(defun warp-pointer ()
  "Warp the cursor to the position last warped from."
  (interactive)
  (let ((curpos (query-pointer)))
    (warp-cursor (car warp-pos) (cdr warp-pos))
    (setq warp-pos curpos)
  )
)

(bind-keys global-keymap "F23"
  '(and (warp-pointer) (system "cursor-locate &")))
```

```sh
#!/bin/bash
# ~/bin/cursor-locate
# can't do this during a screenshot with ImageMagick 'import';
# it locks up Xorg until the screenshot process is killed
if [ -e $HOME/ram/screenshot-in-progress ]; then exit 1 ; fi

#sleep 0.1
# https://github.com/arp242/find-cursor
find-cursor \
  -o 4 --outline-color grey30 \
  -l 2 --color grey70 \
  --size 150 \
  --distance 30 \
  --wait 300 \
  --grow \
  &
```

There are, of course, many other ways to implement the Warp key.  These
examples are just suggestions.

### Launcher keys

The F1 to F12 keys, without any modifiers, emit key events outside the usual
application range, which are meant to be handled by your desktop environment.

- F1: Terminal
- F2: Web search
- F3 to F12: F13 to F22 (base F-key plus 10)

I recommend configuring these in your desktop environment so they will run
scripts with similar names.  That way, you can change their function by
modifying the scripts, without having to remap any keys.  For example...

- F1 ("XF86Explorer" key): Run the "f1" script.
- F2 ("XF86WWW" key): Run the "f2" script.
- F3 to F12 (F13 to F22 keys): Run the "f3" to "f12" scripts.
- Ctrl+Fkeys: Run the "c-f1" to "c-f12" scripts.
- Alt+Fkeys: Run the "a-f1" to "a-f12" scripts.
- Shift+Fkeys: Run the "s-f1" to "s-f12" scripts.
- Hyper+Fkeys: Run the "h-f1" to "h-f12" scripts.

Then in your `~/bin/` and `~/bin/local/` dirs, place scripts matching these
names.  Ideally, they should be symlinks to other scripts.  For example:

```sh
> cd ~/bin
> ls -l f* ?-f*
... f1 -> my-xterm
... f2 -> web-browser
... f3 -> file-manager
... f12 -> screenshot-interactive
... s-f1 -> my-xterm-ipython
... s-f2 -> web-browser-2
... s-f3 -> file-manager-today
... s-f12 -> screenshot-full
```

... and so on.  Make a collection of intuitively-named scripts for common tasks
you want quick access to, and make symlinks to them to apply keybindings.  The
`~/bin/` dir should have common default mappings shared by multiple hosts,
while `~/bin/local/` has overrides which apply on a per-host basis.  These can
also be version-controlled pretty easily.

In this example, F1 launches an XTerm, while Shift+F1 launches an XTerm
preloaded with ipython, which is convenient for use as a calculator.
Similarly, F3 opens a minimal file manager window in whatever dir was last
used, while Shift+F3 opens one in a directory matching the current date.

But these are meant to be mapped to whatever you find useful.  With 12 mappable
keys, and several modifier-key variants of each, there are a lot of
possibilities.

Or if scripts named `f1` to `f12` don't feel right, another suggestion is to
name them `app1` to `app12`.  And perhaps use suffixes instead of prefixes for
the modifier keys.  So instead of `c-f3`, it could be `app3c`.

### Media keys

Includes Play/Pause, Prev Song, and Next Song.

Some models also include Volume-Up and Volume-Down and Mute.

### Knob support (on some models)

- Turn for mouse wheel up/down, or Star+turn for mouse wheel left/right.
- Tap to change mode for extra column, if available.
- Is near Shift, Ctrl, Alt, GUI, and Fn... to provide several knobby functions.

### Dipswitch support (on some models)

For easily switching between two layouts.  Each dipswitch position acts as
a "save slot" to save a favorite layout, and the user can swap between two
favorites by flipping the switch.

### EEPROM

Settings are remembered after unplugging the keyboard.

### Misc extras

- Star+Esc: Puts the keyboard into firmware update mode, so you can reflash the
  firmware without having to open up the case to hit a hidden PCB microswitch.
  Represented by a lightning bolt icon.

- Star+Tab: Prints info about the firmware version, keyboard model, build date,
  and keymap.

- Star+CapsLock: Allows access to the actual CapsLock key, in the rare case
  when you might actually need it.  CapsLock is mostly irrelevant these days
  though, so this likely won't be needed unless the host gets caps stuck on
  somehow.

### Physical design features

- Built for 65% to 75% layouts.

- All Fn keys are in the corners of the keyboard, with their functions in
  matching corners of the keymap diagram, and color-coded for easy
  readability.

- Left-hand and right-hand access to Ctrl, Alt, and GUI... even though
  there aren't always enough physical mod keys.


## Known Issues

- Some settings aren't saved per dipswitch position:
  Backspace/Backslash toggle, Dvoriuk/Dvorak IU/UI toggle.

- Some devices have model-specific issues; check the readme in each keyboard
  directory for details.


## Recommended setup

You may need to use `xmodmap` or `setxkbmap` or similar tools to configure your
keyboard in the host OS before some of the keys here will work.  For example,
here's some `~/.Xmodmap` config I find useful:

```
! revert fancy app launch keycodes back to plain old F13-F24 keys
keycode 191 = F13
keycode 192 = F14
keycode 193 = F15
keycode 194 = F16
keycode 195 = F17
keycode 196 = F18
keycode 197 = F19
keycode 198 = F20
keycode 199 = F21
keycode 200 = F22
keycode 201 = F23
keycode 202 = F24

! reset modifier keys
clear Control
clear Mod4

keycode 105 = Control_R
keycode 108 = Alt_R Meta_R
keycode 133 = Hyper_L Hyper_R Super_L Super_R
keycode 64 = Alt_L Meta_L

add Control = Control_L Control_R
add Mod4 = Hyper_L Hyper_R Super_L Super_R
```

