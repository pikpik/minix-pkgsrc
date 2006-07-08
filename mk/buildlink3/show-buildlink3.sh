#!/bin/sh
#
# $NetBSD$
#
# This script is a helper for the show-buildlink3 target and outputs
# the arguments, each on a new line with any leading "+" signs replaced
# with four spaces.
#

while test $# -gt 0; do
	pkg="$1"
	pkg="${pkg#+}"
	prefix=
	stripped=no
	while test $stripped = no; do
		case $pkg in
		+*)	prefix="    $prefix"; pkg="${pkg#+}"; stripped=no ;;
		*)	stripped=yes ;;
		esac
	done
	echo "$prefix$pkg"
	shift
done
