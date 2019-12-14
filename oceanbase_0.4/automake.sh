#!/bin/sh
#先要安装automake包
aclocal
#生成configuration
autoconf
./build.sh
