#!/bin/sh
#
# $NetBSD$
#
# pkgsrc script to ease mldonkey's startup.
#

if [ ! -d $HOME/mldonkey ]; then
	echo "Creating user's directory ($HOME/mldonkey)..."
	mkdir $HOME/mldonkey
fi

echo "Starting mldonkey..."
cd $HOME/mldonkey
PATH=@PREFIX@/libexec/mldonkey:$PATH
@PREFIX@/libexec/mldonkey/mldonkey > $HOME/mldonkey/log 2>&1
