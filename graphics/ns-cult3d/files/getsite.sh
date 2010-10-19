#!/bin/sh
# $Id$
# 
# Determine the correct BASE URL from which to download $DISTFILE

DISTFILE=$1

BASE_URL=`ftp -o - http://www.cult3d.com/download/viewer/code.js | awk -F '"' '
/'"$DISTFILE"'/ {
	sub(/'"$DISTFILE"'/, "", $2)
        print $2
        exit 0
}'`
if [ -n "$BASE_URL" ] ; then
    echo $BASE_URL
else
    echo "getsites.sh: Unable to extract BASE_URL" >&2
    exit 2
fi
