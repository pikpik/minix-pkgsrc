# $NetBSD$
###
.if !defined(GAMBC_VERSION_MK)
GAMBC_VERSION_MK=	# empty
###
### The package version sets the distribution version.
###
GAMBC_VERSION=		4.2.6
GAMBC_DIST_VERSION=	${GAMBC_VERSION:C|^.*|v&|:S|.|_|g}
.endif
