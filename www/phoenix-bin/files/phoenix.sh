#!@SH@
# $NetBSD: phoenix.sh,v 1.3 2003/05/18 03:43:02 grant Exp $

LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:@PREFIX@/lib/MozillaFirebird-@PLATFORM@:@PREFIX@/lib"
export LD_LIBRARY_PATH

exec @PREFIX@/lib/MozillaFirebird-@PLATFORM@/MozillaFirebird "$@"
