#!/bin/sh
#
# $NetBSD$
#
if [ -x @@PREFIX@@/bin/inndstart -a -s @@INN_DATA_DIR@@/db/active ];
then
 @@PREFIX@@/bin/inndstart >/dev/null 2>&1
 echo -n ' innd'
fi
exit 0
