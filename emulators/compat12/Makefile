# $NetBSD: Makefile,v 1.7 1998/07/15 12:01:42 agc Exp $
#

DISTNAME=	compat12-1.2.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	-${MACHINE_ARCH}.tar.gz

MAINTAINER=	tv@netbsd.org

ONLY_FOR_ARCHS=	i386 m68k ns32k sparc

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKDIR}/lib*.so* ${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
