# $NetBSD: Makefile,v 1.8 2006/06/10 19:59:43 minskim Exp $
#

DISTNAME=	qsubst-20010422
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Query-replace strings in files

USE_BSD_MAKEFILE=	yes

WRKSRC=		${WRKDIR}/qsubst

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

MAKE_ENV+=	BINMODE=${BINMODE}
MAKE_ENV+=	MANMODE=${MANMODE}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
