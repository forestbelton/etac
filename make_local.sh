#!/bin/sh

set -eou pipefail

export CC=gcc-7
export INCLUDES="-I/Users/case/homebrew/Cellar/termbox/1.1.2/include \
	-I/Users/case/homebrew/Cellar/lua/5.3.4_2/include"
export LIBS="-L/Users/case/homebrew/Cellar/termbox/1.1.2/lib \
	-L/Users/case/homebrew/Cellar/lua/5.3.4_2/lib"

TARGET="${1:-}"
make ${TARGET}
