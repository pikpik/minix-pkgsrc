# $NetBSD: Makefile,v 1.4 2007/04/19 15:30:21 xtraeme Exp $

DISTNAME=	suse_libcups-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
DISTFILES=	cups-libs-1.1.23-21.6.${SUSE_ARCH}.rpm

MAINTAINER=	markd@NetBSD.org
COMMENT=	Linux compatibility package for CUPS

EMUL_MODULES.linux=	openssl

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
