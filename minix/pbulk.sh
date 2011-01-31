#!/bin/sh
set -e

# pkgsrc source tree, bootstrap subtree
PKGSRC=/usr/pkgsrc
BOOTSTRAP=$PKGSRC/bootstrap

# New system prefix to install all results in
PREFIX=/usr/pbulk

VARBASE=/usr/pbulk/var

# Compiling during bootstrap
WORKDIR=/usr/tmp/pbulk-bootstrap

# mk.conf pkgsrc read by these pkgsrc binaries
MKCONF=$PREFIX/etc/mk.conf

# Compiling packages
WRKOBJDIR=/usr/tmp/pbulk-outer

# Extra minix mk.conf
MINIXMKCONF=$PKGSRC/minix/mk.conf.minix

if [ ! -f $MINIXMKCONF ]
then	echo "$MINIXMKCONF not found."
	exit 1
fi

dirs="$PREFIX $VARBASE $WORKDIR $WRKOBJDIR"
for d in $dirs
do	if [ -d $d ]
	then	echo "$d exists."
		echo "please remove all of $dirs."
		echo "Then re-run me."
		exit 1
	fi
done

cd $BOOTSTRAP
sh bootstrap --prefix=$PREFIX --varbase=$VARBASE --workdir=$WORKDIR

if [ ! -f $MKCONF ]
then	echo "$MKCONF not found. bootstrap should have generated this."
	exit 1
fi

echo Adding to $MKCONF

echo "# These settings added by Minix pbulk.sh" >>$MKCONF
echo >>$MKCONF .ifdef BSD_PKG_MK
echo "WRKOBJDIR=$WRKOBJDIR" >>$MKCONF
cat $MINIXMKCONF >>$MKCONF
echo >>$MKCONF .endif

echo "Ok. Now install the pbulk build tools in the new hierarchy. Type:"
echo "# cd $PKGSRC/pkgtools/pbulk"
echo "# $PREFIX/bin/bmake package"

echo "When that is done, to make a binary kit, do:"
echo "# cd $BOOTSTRAP"
echo "# sh bootstrap --gzip-binary-kit $BOOTSTRAP/bootstrap.tgz"
