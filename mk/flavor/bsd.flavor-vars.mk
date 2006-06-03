# $NetBSD$
#
# This Makefile fragment is included by bsd.prefs.mk and defines some
# variables which must be defined earlier than where bsd.flavor.mk
# is included.
#

# Default to the pkgsrc-package flavor.
PKG_FLAVOR?=	pkg

.sinclude "${PKGSRCDIR}/mk/flavor/${PKG_FLAVOR}/flavor-vars.mk"
