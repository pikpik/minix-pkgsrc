#!/bin/sh

# Stop execution when an error occurs
set -e

### Jail stuff
# Where to build a pbulk jail
JAILROOT=/usr/pbulk-jail
# Release script used to build the jailed system
RELEASE=/usr/src/tools/release.sh
PKGSRC=/usr/pkgsrc
JAILPKGSRC=$JAILROOT/$PKGSRC
PKGINCACHE=/usr/var/db/pkgin/cache/
JAILPKGINCACHE=$JAILROOT/$PKGINCACHE
PBULK_SH=$PKGSRC/minix/pbulk.sh
SEEDPACKAGES=$PKGSRC/minix/seedpackages/
JAILPBULK_SH=$JAILROOT/$PBULK_SH
PACKAGEURL="ftp://ftp.minix3.org/pub/minix/packages/`uname -r`/`uname -m`/All/"
PACKAGES="binutils gcc44-4.4.5nb3 scmgit-base"
# How to execute commands there
mychroot() {
	chroot $JAILROOT "/bin/sh -c '$1'"
}

my_help() {
	echo "Usage: "
	echo " "
	echo "Jail preparation:"
	echo "  $0 --jail-make    Build $JAILROOT"
	echo "  $0 --jail-pkgsrc  make pkgsrc-create/-update in jail"
	echo " "
	echo "To run pbulk.sh actions within the jail:"
	echo "  $0 --jail-CMD     sh pbulk.sh --CMD chroot in $JAILROOT"
	echo " "
	echo "Wipe current jail, if any, build a new jail,"
	echo "and run a full bulk build in it:"
	echo "  $0 --all          wipe current jail, run -make, -pkgsrc, --jail-all"
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

	return 0
}

makejailseed() {
	if [ -d $SEEDPACKAGES ]
	then	echo " * Copying $SEEDPACKAGES to $JAILPKGINCACHE"
		mkdir -p $JAILPKGINCACHE || true
		cp $SEEDPACKAGES/* $JAILPKGINCACHE
	else	echo " * $SEEDPACKAGES not found, not seeding"
	fi
}

makejailpkgsrc() {
	# Some guest preparation necessary for networking to work
	cp /etc/hosts /etc/resolv.conf $JAILROOT/etc/
	(cd /dev && tar cf - . ) | (cd $JAILROOT/dev ; tar xf -)

	echo " * Installing packages $PACKAGES from $PACKAGEURL"
	for p in $PACKAGES
	do	echo $p ...
		pkg_add -P $JAILROOT $PACKAGEURL/$p
	done

	echo " * Making pkgsrc in jail"
	mychroot "cd /usr && make pkgsrc-create" || true

	echo " * Running pkgsrc-update"
	mychroot "cd /usr && make pkgsrc-update"

	if [ ! -d $JAILPKGSRC ]
	then	echo "Creating $JAILPKGSRC failed."
		exit 1
	fi

	# Fix GCC headers
	mychroot "cd /usr/src && make gnu-includes"

	return 0
}

jailcmd() {
	if [ ! -f $JAILPBULK_SH ]
	then	echo "$JAILPBULK_SH not found; "
		echo "please run $0 --jail-make and --jail-makepkgsrc first."
		exit 1
	fi

	subcmd=`echo $1 | sed 's/--jail-//'`
	mychroot "cd `dirname $PBULK_SH` && sh `basename $PBULK_SH` --jailed --$subcmd"
	return 0
}

jailall() {
	LOGFILE=jail.log
(
	echo "Redirecting output to $LOGFILE"
	exec 2>&1
	set -x
	echo " * Wiping current jail."
	rm -rf $JAILROOT
	echo " * Building jail."
	makejail
	echo " * Seeding packages."
	makejailseed
	echo " * Building pkgsrc in jail."
	makejailpkgsrc
	echo " * Running bulk build."
	jailcmd --jail-all
) | tee $LOGFILE
	return 0
}

case $1 in
	"--jail-make") makejail; break;;
	"--jail-pkgsrc") makejailpkgsrc; break;;
	"--all") jailall; break;;
	--jail-*) jailcmd $1; break;;
	"--help") my_help; break;;
	*) my_help; break;;
esac

exit 0
