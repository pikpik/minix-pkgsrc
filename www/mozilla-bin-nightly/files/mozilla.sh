#!@SH@
# $NetBSD: mozilla.sh,v 1.2 2003/06/11 17:43:16 grant Exp $

LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:@PREFIX@/lib/mozilla-@PLATFORM@:@PREFIX@/lib"
export LD_LIBRARY_PATH

exec @PREFIX@/lib/mozilla-@PLATFORM@/mozilla "$@"
