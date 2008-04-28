# $NetBSD: Makefile,v 1.27 2008/01/05 09:22:06 tonio Exp $

DISTNAME=	mos201src
PKGNAME=	moscow_ml-2.01
CATEGORIES=	lang
MASTER_SITES=	http://www.itu.dk/people/sestoft/mosml/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dina.kvl.dk/~sestoft/mosml.html
COMMENT=	Moscow ML, a version of Standard ML

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/mosml/src
USE_TOOLS+=	perl

BUILD_TARGET=	clean world
MAKE_JOBS_SAFE=	no

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/moscow_ml
	${CP} -R ${WRKDIR}/mosml/examples/* ${DESTDIR}${PREFIX}/share/examples/moscow_ml
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/examples/moscow_ml
	${CHMOD} -R ugo+r ${DESTDIR}${PREFIX}/share/examples/moscow_ml

.include "../../mk/bsd.pkg.mk"
