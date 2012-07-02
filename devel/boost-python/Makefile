# $NetBSD: Makefile,v 1.21 2012/04/08 19:08:49 wiz Exp $

BOOST_PACKAGE=		python
BOOST_COMMENT=		(Boost.Python binary library)
BOOST_CONFIG=		installed

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	lib

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--user-config=${WRKSRC}/user-config.jam
BJAM_ARGS+=		--with-python
MAKE_ENV+=		BOOST_BUILD_PATH=${WRKSRC}

.include "../../devel/boost-jam/bjam.mk"
.include "../../lang/python/application.mk"

post-configure:
	${ECHO} 'using python : ${PYVERSSUFFIX} :' \
	    '${PREFIX}/bin/python${PYVERSSUFFIX} ;' \
	    >${WRKSRC}/user-config.jam

do-build: bjam-build

do-install: boost-install-libs

.include "../../mk/bsd.pkg.mk"
