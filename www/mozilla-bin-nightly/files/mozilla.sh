#!@SH@
# $NetBSD: mozilla.sh,v 1.1.1.1 2003/05/20 14:25:14 grant Exp $

LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:@PREFIX@/lib/mozilla-@PLATFORM@"
export LD_LIBRARY_PATH

exec @PREFIX@/lib/mozilla-@PLATFORM@/mozilla "$@"
