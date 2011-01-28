#!/bin/sh
set -e
PREFIX=/usr/pbulk
VARBASE=/usr/pbulk/var
WORKDIR=/usr/tmp/pbulk-bootstrap
MKCONF=$PREFIX/etc/mk.conf
WRKOBJDIR=/usr/tmp/pbulk-outer
minixdir="`pwd`"
MINIXMKCONF=$minixdir/mk.conf.minix

if [ ! -f $MINIXMKCONF ]
then	echo "$MINIXMKCONF not found. Please run me from the minix/ pkgsrc dir."
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

cd /usr/pkgsrc/bootstrap
sh bootstrap --prefix=/usr/pbulk --varbase=/usr/pbulk/var --workdir=/usr/tmp/pbulk-bootstrap

if [ ! -f $MKCONF ]
then	echo "$MKCONF not found. bootstrap should have generated this."
	exit 1
fi

echo Adding to $MKCONF

echo "# These settings added by Minix pbulk.sh" >>$MKCONF
echo >>$MKCONF .ifdef BSD_PKG_MK
echo "WRKOBJDIR=$WRKOBJDIR"
cat $MINIXMKCONF >>$MKCONF
echo >>$MKCONF .endif

echo "Ok. Now install the pbulk build tools in the new hierarchy. Type:"
echo "# cd /usr/pkgsrc/pkgtools/pbulk"
echo "# $PREFIX/bin/bmake package"

echo "When that is done, to make a binary kit, do:"
echo "# cd /usr/pkgsrc/bootstrap"
echo "# sh bootstrap --gzip-binary-kit /usr/pkgsrc/bootstrap/bootstrap.tgz"
