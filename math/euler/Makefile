# $NetBSD$

DISTNAME=		euler-1.60.2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=euler/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://euler.sourceforge.net/index.html
COMMENT=		Interactive numerical analysis and graphics program

WRKSRC=			${WRKDIR}/euler-1.60/source
MAKEFILE=		makefile
ALL_TARGET=		euler
USE_BUILDLINK_ONLY=	# defined

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
