#!/bin/sh
#
# $NetBSD$
#
# This script is invoked as:
#
# 	smalleiffel <cmd> [<arg> ...]
#
# where <cmd> is one of the programs in @@SE@@/bin.
#
SmallEiffel=@@SE@@/sys/system.se ; export SmallEiffel
se_cmd=@@SE@@/bin/$1
if [ -x ${se_cmd} ]
then
	shift
	exec ${se_cmd} ${1+$@}
else
	echo "smalleiffel: command ${se_cmd} not found."
fi
