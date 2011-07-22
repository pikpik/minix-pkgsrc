#!/bin/sh

# Stop execution when an error occurs
set -e

# Certain certainties
RELEASE=/usr/src/tools/release.sh
PKGSRC=/usr/pkgsrc
PACKAGEURL="ftp://ftp.minix3.org/pub/minix/packages/`uname -r`/`uname -m`/All/"
PACKAGES="binutils gcc44-4.4.5nb3 scmgit-base"
JAILROOTBASE=/usr/pbulk-jail
BRANCH=minix-master
REMOTE=pkgsrc

# Jail-dependent vars
initvars() {
	# Where to build a pbulk jail
	if [ "$JAILDEV" ]
	then	umount $JAILDEV || true
		echo "mkfs $JAILDEV .."
		mkfs.mfs $JAILDEV
		JAILROOT=$JAILROOTBASE.`basename $JAILDEV`
		mkdir $JAILROOT || true
		mount $JAILDEV $JAILROOT
	else	JAILROOT=$JAILROOTBASE
	fi

	# Release script used to build the jailed system
	JAILPKGSRC=$JAILROOT/$PKGSRC
	PBULK_SH=$PKGSRC/minix/pbulk.sh
	JAILPBULK_SH=$JAILROOT/$PBULK_SH
}

# How to execute commands there
mychroot() {
	chroot $JAILROOT "/bin/sh -c '$1'"
}

my_help() {
	echo "Usage: "
	echo "  # pbulk-jail.sh [-d<dev>] [-A] [-h]"
	echo " "
	echo "Jail options:"
	echo "  $0 -d<dev> mkfs and use /dev/<dev> for jail FS"
	echo " "
	echo "Wipe current jail, if any, build a new jail,"
	echo "and run a full bulk build in it:"
	echo "  $0 -A"
}

makejail() {

	# Execute jail creating script that builds a new minix
	# in $JAILROOT from the latest git repository
	cd `dirname $RELEASE`
	sh `basename $RELEASE` -j$JAILROOT -p

	return 0
}

makejailpkgsrc() {
	echo " * Installing packages $PACKAGES from $PACKAGEURL"
	for p in $PACKAGES
	do	echo $p ...
		pkg_add -P $JAILROOT $PACKAGEURL/$p
	done

	# copy our own pkgsrc repository there so the new repository
	# doesn't have to retrieve objects we already have
	GITDIR=$JAILPKGSRC/.git
	mkdir -p $GITDIR
	synctree -f $PKGSRC/.git $GITDIR >/dev/null
	(	cd $JAILPKGSRC
		git remote rm $REMOTE || true
		git remote add $REMOTE git://git.minix3.org/pkgsrc.git
		git fetch $REMOTE
		git checkout -f $REMOTE/$BRANCH
	)

	# Fix GCC headers
	mychroot "cd /usr/src && make gnu-includes"

	return 0
}

jailcmd() {
	mychroot "cd `dirname $PBULK_SH` && sh `basename $PBULK_SH` --jailed --all"
	return 0
}

jailall() {
	LOGFILE=jail.log
(
	echo "Redirecting output to $LOGFILE"
	exec 2>&1
	set -x
	echo " * Building jail."
	makejail
	echo " * Building pkgsrc in jail."
	makejailpkgsrc
	echo " * Running bulk build."
	jailall
) | tee $LOGFILE
	return 0
}

initvars

while getopts "u:d:Ah" opt
do
	case $opt in
	d) JAILDEV=$OPTARG; initvars; ;;
	A) jailall; ;;
	h) my_help; ;;
	*) my_help; exit 1; ;;
	esac
done

exit 0
