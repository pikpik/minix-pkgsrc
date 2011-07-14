#!/bin/sh

#####
##
## Minix pBulk Bootstrap Script
##
#####

# Stop execution when an error occurs
set -e

# Set output verbosity (0=quiet, 1=normal, 2=debug)
PKG_DEBUG_LEVEL=2

# This is set if we are running from a jail hierarchy.
# If so, we don't have to be too careful with wiping out
# directories; we are running in a throw-away, reproducible
# environment.
JAILED=0

pbulksh_help() {
	echo "Usage: "
	echo "  $0 --bootstrap   Do the initial bootstrap"
	echo "  $0 --backup      Backup /usr/pkg to a safe place"
	echo "  $0 --bin-kit     Create a binary kit"
	echo "  $0 --build       Execute bulkbuild"
	echo "  $0 --restore     Restore /usr/pkg"
	echo "  $0 --all         Do all steps mentioned above"
	echo "  $0 --help        Display this message"
}

# Preparation -- bootstraps a pkgsrc installation into /usr/pbulk
pbulksh_bootstrap() {

	dirs="/usr/pbulk /usr/pbulk-packages /usr/tmp/pbulk-bootstrap /usr/tmp/pbulk-outer /usr/pbulk-logs /usr/pkgsrc/packages/$(uname -r)/"

	if [ $JAILED = 1 ]
	then	rm -rf $dirs
	fi

	for d in $dirs
	do      if [ -d $d ]
	        then    echo "$d exists."
	                echo "please remove all of $dirs"
	                echo "Then re-run me."
	                exit 1
	        fi
	done

	cd /usr/pkgsrc

	sh ./bootstrap/bootstrap --prefix=/usr/pbulk \
			--varbase=/usr/pbulk/var \
			--workdir=/usr/tmp/pbulk-bootstrap \
			--pkgdbdir=/usr/pbulk/.pkgdb \
			--mk-fragment=/usr/pkgsrc/minix/mk.conf.minix.pbulk

	rm -rf /usr/tmp/pbulk-bootstrap
	rm -rf /usr/pkgsrc/packages/$(uname -r)/

	# Install pbulk into /usr/pbulk
	cd /usr/pkgsrc/pkgtools/pbulk
	env PATH=/usr/pbulk/bin:/usr/pbulk/sbin:${PATH} bmake install package
	sed -e 's/OP_SYS_VER/'$(uname -r)'/g' /usr/pkgsrc/minix/pbulk.conf > /usr/pbulk/etc/pbulk.conf
}

# In order to build proper packages, we need to work in /usr/pkg.
# Here, we back up /usr/pkg as well as VARBASE.
pbulksh_backup() {

	dirs="/usr/pkg.sav /usr/var.sav"
	for d in $dirs
	do      if [ -d $d ]
	        then    echo "$d exists."
	                echo "Did you already run --backup?"
	                exit 1
	        fi
	done

	mv /usr/pkg /usr/pkg.sav
	mkdir /usr/pkg
	mv /usr/var /usr/var.sav
	mkdir /usr/var
}

# Create a bootstrap a binary kit. pbulk needs this.
pbulksh_bin_kit() {

	dirs="/usr/pkg.sav /usr/var.sav"
	for d in $dirs
	do      if [ ! -d $d ]
	        then    echo "$d doesn't exist."
	                echo "Re-run with --backup to back it up"
	                exit 1
	        fi
	done

	cd /usr/pkgsrc
	rm -f /usr/pkgsrc/bootstrap/bootstrap.tar.gz
	sh ./bootstrap/cleanup

	# Trim the .ifdef BSD_PKG_MK and .endif lines to make a "fragment"
	sed -e '1d;$d' /usr/pkgsrc/minix/mk.conf.minix > /usr/pkgsrc/minix/mk.conf.minix.frag

	env PATH=/usr/pbulk/bin:/usr/pbulk/sbin:/usr/pkg.sav/gcc44/bin:/usr/pkg.sav/bin:/usr/pkg.sav/sbin:${PATH} sh ./bootstrap/bootstrap \
		--mk-fragment=/usr/pkgsrc/minix/mk.conf.minix.frag \
		--gzip-binary-kit=/usr/pkgsrc/bootstrap/bootstrap.tar.gz \
		--varbase=/usr/var \
		--pkgdbdir=/usr/var/db/pkg
	rm -f /usr/pkgsrc/minix/mk.conf.minix.frag

	rm -rf /usr/pbulk-packages
	rm -rf /usr/pkgsrc/packages/$(uname -r)/

	# Use the same mk.conf that our users instead of the hybrid auto-generated mk.conf from bootstrap
	cd /usr/pkgsrc/bootstrap
	mkdir temp
	mv bootstrap.tar.gz temp
	cd temp
	tar xf bootstrap.tar.gz
	cp /usr/pkgsrc/minix/mk.conf.minix usr/pkg/etc/mk.conf
	tar hzcf ../bootstrap.tar.gz usr
	cd ..
	rm -rf temp
	cd /usr/pkgsrc
}

# Perform the bulk build. Most configuration is in pbulk.conf
pbulksh_build() {


	if [ ! -f /usr/pkgsrc/bootstrap/bootstrap.tar.gz ]
	then
		echo "/usr/pkgsrc/bootstrap/bootstrap.tar.gz doesn't exist"
		echo "Re-run with --bin-kit to create it"
		exit 1
	fi

	if [ ! -d /usr/pbulk ]
	then
		echo "/usr/pbulk doesn't exist"
		echo "Re-run with --bootstrap to create it"
		exit 1
	fi

	env PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/pbulk/bin:/usr/pbulk/sbin:/usr/pkg.sav/gcc44/bin:/usr/pkg.sav/bin:/usr/pkg.sav/sbin:${PATH} /usr/pbulk/bin/bulkbuild
}

# Restore the backed up /usr/pkg and /usr/var
pbulksh_restore() {

	dirs="/usr/pkg.sav /usr/var.sav"
	for d in $dirs
	do      if [ ! -d $d ]
	        then    echo "$d doesn't exist."
	                echo "Can't restore without it."
	                exit 1
	        fi
	done

	rm -rf /usr/pkg
	mv /usr/pkg.sav /usr/pkg
	rm -rf /usr/var
	mv /usr/var.sav /usr/var
}

pbulksh_all() {

	pbulksh_bootstrap
	pbulksh_backup
	pbulksh_bin_kit
	pbulksh_build
	pbulksh_restore
}

if [ $1 = --jailed ]
then	JAILED=1
	shift
fi

case $1 in
	"--bootstrap") pbulksh_bootstrap; break;;
	"--backup") pbulksh_backup; break;;
	"--bin-kit") pbulksh_bin_kit; break;;
	"--build") pbulksh_build; break;;
	"--restore") pbulksh_restore; break;;
	"--all") pbulksh_all; break;;
	"--help") pbulksh_help; break;;
	*) pbulksh_help; break;;
esac
