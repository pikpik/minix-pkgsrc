# $NetBSD: Makefile,v 1.2 2001/02/17 17:21:47 wiz Exp $

DISTNAME=	tvtwm.pl11
PKGNAME=	tvtwm-11
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=window_managers/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Classic twm with virtual desktop support

USE_BUILDLINK_ONLY=	YES
USE_IMAKE=		YES

WRKSRC=		${WRKDIR}/tvtwm

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
