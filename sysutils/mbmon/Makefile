# $NetBSD$
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-201

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	
COMMENT=	motherboard monitoring utility

ALL_TARGET=	mbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
