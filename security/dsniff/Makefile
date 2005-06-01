# $NetBSD: Makefile,v 1.24 2005/03/22 01:07:07 wiz Exp $

.include "Makefile.common"

PKGREVISION=	4
COMMENT=	Password sniffer (webspy)

DEPENDS+=	dsniff-nox11-[0-9]*:../../security/dsniff-nox11

BUILD_TARGET=	libmissing.a webspy

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webspy ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/webspy.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
