# $NetBSD: Makefile,v 1.21 2004/04/11 08:12:34 snj Exp $

DISTNAME=	hexedit-1.2.10
CATEGORIES=	editors
MASTER_SITES=	http://merd.net/pixel/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://merd.net/pixel/hexedit.html
COMMENT=	To view and edit files in hexadecimal or ASCII

WRKSRC=			${WRKDIR}/hexedit
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
