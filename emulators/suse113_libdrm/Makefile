# $NetBSD: Makefile,v 1.2 2011/02/10 02:55:46 chs Exp $

DISTNAME=	suse_libdrm-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES+=	libdrm-2.4.21-1.2.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for libdrm

EMUL_MODULES.linux=	x11

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
