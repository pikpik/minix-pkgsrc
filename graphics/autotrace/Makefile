# $NetBSD: Makefile,v 1.7 2001/10/24 22:10:59 jlam Exp $
#

DISTNAME=	autotrace-0.29
CATEGORIES=	graphics cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autotrace/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://autotrace.sourceforge.net/
COMMENT=	convert bitmap to vector graphics

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../graphics/ImageMagick/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
