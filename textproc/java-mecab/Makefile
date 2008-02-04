# $NetBSD: Makefile,v 1.1.1.1 2007/05/12 13:53:46 obache Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-java-${MECAB_VERSION}
PKGNAME=	java-mecab-${MECAB_VERSION}
CATEGORIES+=	java

COMMENT=	MeCab java module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

TEST_TARGET=	test

do-install:
	${INSTALL_LIB} ${WRKSRC}/libMeCab.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/MeCab.jar ${DESTDIR}${PREFIX}/lib

BUILDLINK_API_DEPENDS.mecab+=	mecab>=${MECAB_VERSION}

.include "../../textproc/mecab/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
