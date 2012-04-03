# $NetBSD: Makefile,v 1.5 2010/05/16 01:11:46 obache Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-ipadic-2.7.0-20070610
PKGNAME=	mecab-ipadic-2.7.0.20070610
PKGREVISION=	1

COMMENT=	Japanese Morphological Dictionary for MeCab
#LICENSE=	# See ${WRKSRC}/COPYING

BUILD_DEPENDS+=	mecab-base-[0-9]*:../../textproc/mecab-base

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-charset=${MECAB_CHARSET:Q}

BUILD_DEFS+=		MECAB_CHARSET

FIND_PREFIX:=	MECABDIR=mecab-base
.include "../../mk/find-prefix.mk"
CONFIGURE_ARGS+=	--with-mecab-config=${MECABDIR}/bin/mecab-config

.include "../../mk/bsd.pkg.mk"
