# $NetBSD: Makefile,v 1.1.1.1 2010/09/24 01:28:04 chs Exp $

DISTNAME=	suse_libtiff-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
DISTFILES=	libtiff3-3.9.2-5.2.1.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for TIFF

EMUL_MODULES.linux=	jpeg

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
