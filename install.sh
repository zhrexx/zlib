#!/bin/bash

echo "Installing zlib"

if [ ! -d "zlib" ]; then
    echo "Cloning zlib repository..."
    git clone https://github.com/zhrxxgroup/zlib.git
else
    echo "zlib repository already exists. Skipping clone."
fi

set -e
sudo cp -r zlib/libs/* /usr/include/zlib

echo "zlib installed successfully!"
