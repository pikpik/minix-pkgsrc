#!/bin/sh
# $NetBSD$

case $1 in
start)
	INSTANCE_HOME=@INSTANCEHOME@
	export INSTANCE_HOME
	(cd @INSTANCEHOME@ && @PYTHONBIN@ @ZOPEDIR@/z2.py)
	;;
stop)
	kill `cat @INSTANCEHOME@/var/Z2.pid`
	;;
esac
