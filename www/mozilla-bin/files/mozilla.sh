#!@SH@
# $NetBSD: mozilla.sh,v 1.2 2003/04/14 22:50:19 grant Exp $

LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:@PREFIX@/lib/mozilla-@PLATFORM@:@PREFIX@/lib"
export LD_LIBRARY_PATH

exec @PREFIX@/lib/mozilla-@PLATFORM@/mozilla "$@"
