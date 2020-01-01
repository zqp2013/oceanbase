#!/bin/sh
export DRC_ROOT=/usr/bin

export TBLIB_ROOT=/usr/local
#/home/qpzhou/sources/tb-common-utils

export EASY_ROOT=/usr/local
# tail depends libeasy :make install

export JAVA_HOME=/usr/lib/jvm/java-1.8.0-openjdk-amd64


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

#apt-get install libaio-dev
#lzo  实时压缩库
#snappy  Google的压缩解压库   -fPIC


#: undefined reference to symbol 'x509_free@@openssl_1_1_0'
# -lcrypto

#gtest

#libobsql.so要用到mysqlclient库
#apt-cache search libmysqlclient-dev
#apt-get install default-libmysqlclient-dev



#/usr/bin/ld: cannot find -lnuma
#/usr/bin/ld: cannot find -lreadline
#/usr/bin/ld: cannot find -lncurses


#jni.h: No such file or directory
#apt-get install openjdk-8-jdk
