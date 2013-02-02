# $NetBSD: Makefile,v 1.2 2009/08/12 17:17:42 minskim Exp $

.include "../../devel/lua-stdlib/Makefile.common"

PKGNAME=		${DISTNAME:S/stdlib/lua-stdlib-doc/}
MAINTAINER=		cheusov@NetBSD.org

COMMENT=		Documentation for modules from lua-stdlib

DOCDIR=			share/doc/lua-stdlib

DEPENDS+=		lua-${DISTNAME}{,nb*}:../../devel/lua-stdlib
INSTALLATION_DIRS+=	${DOCDIR}/modules

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.html \
	                ${DESTDIR}${PREFIX}/${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/src/modules/*.html \
	                ${DESTDIR}${PREFIX}/${DOCDIR}/modules/

.include "../../mk/bsd.pkg.mk"
