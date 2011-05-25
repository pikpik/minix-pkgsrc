#!/bin/sh
set -e

#####
##
## Minix pBulk Bootstrap Script
##
#####

# Set output verbosity (0=quiet, 1=normal, 2=debug)
PKG_DEBUG_LEVEL=2

# TODO consider splitting this up into several scripts or adding
# command line arguments to enable someone to run one specific part
# (i.e. just bootstrap or just run a bulkbuild if a bootstrap has been done).

# TODO add check for compilers and other things needed for the build

# TODO double check that this list is complete and accurate
dirs="/usr/pbulk /usr/pbulk_build /usr/pbulk-packages /usr/tmp/pbulk-bootstrap /usr/tmp/pbulk-outer /usr/tmp/pbulk_build-bootstrap /usr/tmp/pbulk_build-outer"
for d in $dirs
do      if [ -d $d ]
        then    echo "$d exists."
                echo "please remove all of $dirs."
                echo "Then re-run me."
                exit 1
        fi
done

# Preparation -- bootstraps a pkgsrc installation into /usr/pbulk
# Defining variables for these paths would be nice, but it pollutes the
# environment and some of the later commands get confused.
cd /usr/pkgsrc
sh ./bootstrap/bootstrap --prefix=/usr/pbulk --varbase=/usr/pbulk/var --workdir=/usr/tmp/pbulk-bootstrap --pkgdbdir=/usr/pbulk/.pkgdb --mk-fragment=/usr/pkgsrc/minix/mk.conf.minix.pbulk
rm -rf /usr/tmp/pbulk-bootstrap

# Install pbulk into /usr/pbulk
cd /usr/pkgsrc/pkgtools/pbulk
env PATH=/usr/pbulk/bin:/usr/pbulk/sbin:${PATH} bmake install package

# In order to build proper packages, we need to work in /usr/pkg.
# Here, we back up /usr/pkg as well as VARBASE.
mv /usr/pkg /usr/pkg.sav
mkdir /usr/pkg
mv /usr/var /usr/var.sav
mkdir /usr/var

# Create a bootstrap a binary kit. pbulk needs this.
cd /usr/pkgsrc
sh ./bootstrap/cleanup
env PATH=/usr/pbulk/bin:/usr/pbulk/sbin:/usr/pkg.sav/bin:/usr/pkg.sav/sbin:${PATH} sh ./bootstrap/bootstrap \
	--mk-fragment=/usr/pkgsrc/minix/mk.conf.minix \
	--gzip-binary-kit=/usr/pkgsrc/bootstrap/bootstrap.tar.gz \
	--varbase=/usr/var \
	--pkgdbdir=/usr/var/db/pkg

rm -rf /usr/pbulk-packages

# Perform the bulk build. Most configuration is in pbulk.conf
cp /usr/pkgsrc/minix/pbulk.conf /usr/pbulk/etc/pbulk.conf
env PATH=/usr/pkg.sav/bin:/usr/pkg.sav/sbin:${PATH} /usr/pbulk/bin/bulkbuild

# Restore the backed up /usr/pkg and /usr/var
rm -rf /usr/pkg
mv /usr/pkg.sav /usr/pkg
rm -rf /usr/var
mv /usr/var.sav /usr/var
