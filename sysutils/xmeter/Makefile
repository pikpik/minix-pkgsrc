# $NetBSD: Makefile,v 1.10 2006/03/04 21:30:44 jlam Exp $
#

DISTNAME=	xmeter-1.15
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=misdirected/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	#
COMMENT=	Distributed system load meter for X11

WRKSRC=		${WRKDIR}
USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
