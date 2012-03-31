# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:38:22 obache Exp $

DISTNAME=	suse_libpng-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libpng14-14-1.4.10-3.6.1.${SUSE_ARCH}
RPMUPDPKGS+=	libpng12-0-1.2.48-9.6.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for PNG

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
