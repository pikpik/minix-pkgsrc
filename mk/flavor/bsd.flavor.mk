# $NetBSD$
#
# This Makefile fragment is included by bsd.pkg.mk and pulls in the correct
# target and variable overrides for the selected package system flavor.
#

.include "${PKGSRCDIR}/mk/flavor/${PKG_FLAVOR}/flavor.mk"
