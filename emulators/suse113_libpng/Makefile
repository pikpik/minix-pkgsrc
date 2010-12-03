# $NetBSD: Makefile,v 1.1.1.1 2010/09/24 01:28:02 chs Exp $

DISTNAME=	suse_libpng-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
DISTFILES=	libpng14-14-1.4.3-2.1.${SUSE_ARCH}.rpm \
		libpng12-0-1.2.44-2.1.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for PNG

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
