#!/bin/sh
#
# $NetBSD$
#
MOZILLA_HOME=@@MOZILLA_HOME@@ ;	export MOZILLA_HOME
XNLSPATH=$MOZILLA_HOME/nls ;		export XNLSPATH
XKEYSYMDB=$MOZILLA_HOME/XKeysymDB ;	export XKEYSYMDB
exec $MOZILLA_HOME/netscape ${1+$@}      
