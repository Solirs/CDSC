#!/bin/sh

# Generate default environment variables for compilation
export CC="gcc"
export MAKE="make"
export CFLAGS="-std=c11 -Wextra -Wall -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast"
