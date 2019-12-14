#!/bin/sh
#先要安装automake包，生成aclocal.m4
aclocal
#根据configure.ac及aclocal.m4生成configuration
autoconf
./build.sh
