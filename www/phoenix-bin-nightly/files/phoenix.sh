#!@SH@
# $NetBSD: phoenix.sh,v 1.1.1.1 2003/03/26 12:55:04 grant Exp $

LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:@PREFIX@/lib/phoenix-@PLATFORM@"
export LD_LIBRARY_PATH

exec @PREFIX@/lib/phoenix-@PLATFORM@/phoenix "$@"
