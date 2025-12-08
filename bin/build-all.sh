#!/bin/bash
cd ~/src/qmk/qmk_firmware/
source .venv/bin/activate
qmk userspace-compile
