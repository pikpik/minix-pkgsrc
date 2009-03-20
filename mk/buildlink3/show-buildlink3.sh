#!/bin/sh
#
# $NetBSD: show-buildlink3.sh,v 1.1 2006/07/08 23:11:17 jlam Exp $
#
# This script is a helper for the show-buildlink3 target and outputs
# the arguments as tree.
#

while test $# -gt 0; do
	pkg="$1"
	case $pkg in
	-*)
		indentation=${indendation#    }
		;;
	*)
		echo "${indentation}${pkg}"
		indentation="${indentation}    "
		;;
	esac
	shift
done
