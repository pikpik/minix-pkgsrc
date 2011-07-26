# $NetBSD: Makefile,v 1.1.1.1 2009/02/12 01:45:01 minskim Exp $

.include "../../devel/lua-stdlib/Makefile.common"

PKGNAME=		${DISTNAME:S/stdlib/${LUA_PKGPREFIX}-stdlib/}
PKGREVISION=		1
COMMENT=		Standard library for Lua programming language

DEPENDS+=		lua-lrexlib-pcre-[0-9]*:../../devel/lua-lrexlib-pcre
INSTALLATION_DIRS+=	${LUA_LDIR}

.include "../../lang/lua/module.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/modules/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../mk/bsd.pkg.mk"
