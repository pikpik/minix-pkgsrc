#!@SH@
#
# $NetBSD: opera.sh,v 1.4 2007/08/07 21:37:25 jlam Exp $
#
# This script is used with linux-* emulations to ensure that opera is
# started with the proper environment.
#

# Fix up LD_LIBRARY_PATH so that /lib is always searched for shared
# libraries.
#
LD_LIBRARY_PATH=/lib:/usr/lib; export LD_LIBRARY_PATH

exec @EMULDIR@/bin/bash /usr/bin/opera "$@"
