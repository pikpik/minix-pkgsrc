# $NetBSD: Makefile,v 1.5 2002/03/13 17:37:22 fredb Exp $

DISTNAME=	wmbiff-0.3.1
PKGREVISION=	1
CATEGORIES=	mail x11
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=wmbiff/)

MAINTAINER=	magick@zhadum.de
HOMEPAGE=	http://sourceforge.net/projects/wmbiff/
COMMENT=	xbuffy like "mail-checker" for WindowMaker

USE_BUILDLINK2=	YES
USE_X11=	YES
USE_GMAKE=	YES

WRKSRC=		${WRKDIR}/${DISTNAME}/wmbiff

.include "../../graphics/xpm/buildlink2.mk"
.include "../../wm/windowmaker/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
