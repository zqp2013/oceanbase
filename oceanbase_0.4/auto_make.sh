#!/bin/sh
export DRC_ROOT=/usr/bin/
export TBLIB_ROOT=/home/qpzhou/sources/tb-common-utils/
export EASY_ROOT=/home/qpzhou/sources/libeasy/

libtoolize --force
aclocal
automake --force-missing --add-missing
autoconf
./configure


#先要安装automake包，生成aclocal.m4
#aclocal
#根据configure.ac及aclocal.m4生成configuration
#autoconf
#./build.sh
#One also needs to run 'autoreconf -i' before rerunning ./configure - it will install the missing files that ./configure is complaining about.

