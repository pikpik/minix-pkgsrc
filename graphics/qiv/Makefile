# $NetBSD: Makefile,v 1.12 2004/01/24 15:46:44 grant Exp $

DISTNAME=	qiv-1.9-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.klografx.net/qiv/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://www.klografx.net/qiv/
COMMENT=	Quick image viewer

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
