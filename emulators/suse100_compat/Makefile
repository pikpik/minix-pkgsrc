# $NetBSD: Makefile,v 1.6 2007/04/19 15:30:20 xtraeme Exp $

DISTNAME=	suse_compat-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
DISTFILES+=	compat-2004.11.13-4.${SUSE_ARCH}.rpm			\
		compat-g77-3.3.5-2.${SUSE_ARCH}.rpm			\
		compat-libstdc++-5.0.7-6.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package with old shared libraries

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
