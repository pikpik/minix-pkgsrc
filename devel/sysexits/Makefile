# $NetBSD: Makefile,v 1.23 2005/06/16 06:57:46 jlam Exp $
#

DISTNAME=	sysexits-1.0
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Substitute <sysexits.h> for OS's lacking it

NO_CHECKSUM=	YES
NO_BUILD=	YES

INSTALLATION_DIRS=	include

do-install:
	${INSTALL_DATA} ${FILESDIR}/sysexits.h ${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
