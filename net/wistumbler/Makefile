# $NetBSD: Makefile,v 1.4 2002/08/09 13:36:51 wiz Exp $

DISTNAME=	wistumbler-20020809
CATEGORIES=	net
MASTER_SITES=	http://gongon.com/persons/iseki/wistumbler/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gongon.com/persons/iseki/wistumbler/
COMMENT=	Network stumbler for WaveLAN/IEEE wireless networking

USE_BUILDLINK_ONLY=	YES

WRKSRC=		${WRKDIR}/wistumbler

NOT_FOR_PLATFORM=	NetBSD-0.*-* NetBSD-1.[01234]*-* NetBSD-1.5-*
NOT_FOR_PLATFORM+=	NetBSD-1.5.*-* NetBSD-1.5[A-V]-*

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
