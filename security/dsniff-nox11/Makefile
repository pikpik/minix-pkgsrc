# $NetBSD: Makefile,v 1.23 2005/02/05 16:11:48 adrianp Exp $

.include "../dsniff/Makefile.common"

PKGNAME=	dsniff-nox11-${VERS}
COMMENT=	Password sniffer

CONFIGURE_ARGS+=	--without-x

post-install:
	${RM} ${PREFIX}/man/man8/webspy.8

.include "../../mk/bsd.pkg.mk"
