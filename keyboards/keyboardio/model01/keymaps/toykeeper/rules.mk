# Compile options for ToyKeeper's Keyboardio Model01 layout
# Copyright 2022-2025 Selene ToyKeeper
# SPDX-License-Identifier: GPL-3.0-or-later
# (see users/toykeeper/rules.mk for the rest of the options)

# dang, this board can't use QMK's debouncing
#DEBOUNCE_TYPE = sym_eager_pk

# needed for the "Any" key, but it takes too much space
DEFERRED_EXEC_ENABLE = no

