#!/bin/sh

# Stop execution when an error occurs
set -e

### Jail stuff
# Where to build a pbulk jail
JAILROOT=/usr/pbulk-jail
# Release script used to build the jailed system
RELEASE=/usr/src/tools/release.sh
PKGSRC=/usr/pkgsrc
SEEDPACKAGES=$PKGSRC/packages/`uname -r`/`uname -p`/All/
JAILPKGSRC=$JAILROOT/$PKGSRC
JAILPKGINCACHE=$JAILROOT/usr/var/db/pkgin/cache/
PBULK_SH=$PKGSRC/minix/pbulk.sh
JAILPBULK_SH=$JAILROOT/$PBULK_SH
PACKAGES="binutils gcc44 scmgit-base"
# How to execute commands there
mychroot() {
	chroot $JAILROOT "/bin/sh -c '$1'"
}

my_help() {
	echo "Usage: "
	echo " "
	echo "  $0 --jail-make    Build $JAILROOT"
	echo "  $0 --jail-seed    add local packages to jail pkgin cache"
	echo "  $0 --jail-pkgsrc  make pkgsrc-create/-update in jail"
	echo "  $0 --jail-CMD     sh pbulk.sh --CMD chroot in $JAILROOT"
	echo " "
	echo "Options:"
}

makejail() {
	# Sanity check jail making
	if [ -d $JAILROOT ]
	then	echo "$JAILROOT already exists; please wipe it first."
		exit 1
	fi

	# Execute jail creating script that builds a new minix
	# in $JAILROOT from the latest git repository
	cd `dirname $RELEASE`
	sh `basename $RELEASE` -j$JAILROOT -p

	# Check it worked
	if [ ! -d $JAILROOT ]
	then	echo "No $JAILROOT; making jail failed!"
		exit 1
	fi

	exit 0
}

makejailseed() {
	echo " * Copying $SEEDPACKAGES to $JAILPKGINCACHE"
	mkdir -p $JAILPKGINCACHE || true
	cp $SEEDPACKAGES/* $JAILPKGINCACHE
}

makejailpkgsrc() {
	# Some guest preparation necessary for networking to work
	cp /etc/hosts /etc/resolv.conf $JAILROOT/etc/
	(cd /dev && tar cf - . ) | (cd $JAILROOT/dev ; tar xf -)

	echo " * Installing packages $PACKAGES with pkgin"
	mychroot "pkgin -y in $PACKAGES"

	echo " * Creating/updating pkgsrc in $JAILROOT"
	mychroot "cd /usr ; make pkgsrc-create ; make pkgsrc-update"

	if [ ! -d $JAILPKGSRC ]
	then	echo "Creating $JAILPKGSRC failed."
		exit 1
	fi
	exit 0
}

jailcmd() {
	if [ ! -f $JAILPBULK_SH ]
	then	echo "$JAILPBULK_SH not found; "
		echo "please run $0 --jail-make and --jail-makepkgsrc first."
		exit 1
	fi

	subcmd=`echo $1 | sed 's/--jail-//'`
	mychroot "cd `dirname $PBULK_SH` && sh `basename $PBULK_SH` --jailed --$subcmd"
	exit 0
}

case $1 in
	"--jail-make") makejail; break;;
	"--jail-pkgsrc") makejailpkgsrc; break;;
	"--jail-seed") makejailseed; break;;
	--jail-*) jailcmd $1; break;;
	"--help") my_help; break;;
	*) my_help; break;;
esac
