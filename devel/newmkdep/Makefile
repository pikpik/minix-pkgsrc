# $NetBSD: Makefile,v 1.10 2003/07/21 16:43:33 martti Exp $

DISTNAME=	newmkdep-1.0
CATEGORIES=	devel
MASTER_SITES=	http://core.de/~tron/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Faster replacement for *BSD's "mkdep"

WRKSRC=		${WRKDIR}/newmkdep
NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-I/usr/include -I${ZOULARISBASE}/include
LDFLAGS+=	-L${ZOULARISBASE}/lib -lbsdcompat
.endif

.include "../../mk/bsd.pkg.mk"
