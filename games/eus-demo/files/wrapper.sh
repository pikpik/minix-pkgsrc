#!/bin/sh -e
# $NetBSD$
# Simple wrapper for lokigames @@BINNAME@@

# linux binary calls mkdir for this with a trailing '/'
if [ ! -d $HOME/.loki ];then
    mkdir $HOME/.loki
fi
cd @@LIBDIR@@
exec ./@@BINNAME@@ $@
