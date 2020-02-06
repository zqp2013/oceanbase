#!/bin/sh
#gdb -tui /usr/local/bin/rootserver
#set args -c /home/qpzhou/source/oceanbase/oceanbase_0.4/qpzhou/etc/rootserver.conf -N

gdb -tui /usr/local/bin/chunkserver
set args -c /home/qpzhou/source/oceanbase/oceanbase_0.4/qpzhou/etc/chunkserver.conf -N
