# $NetBSD: Makefile,v 1.7 2004/01/20 12:22:22 agc Exp $

DISTNAME=	xrmftp-1.2.4
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.mat.uni.torun.pl/~rafmet/xrmftp/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.mat.uni.torun.pl/~rafmet/xrmftp/
COMMENT=	FTP client for X Window System

WRKSRC=		${WRKDIR}/${DISTNAME}.src
USE_BUILDLINK3=	yes
USE_X11BASE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrmftp ${PREFIX}/bin

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
