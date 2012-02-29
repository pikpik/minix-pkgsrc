# $NetBSD: Makefile,v 1.1.1.1 2011/03/23 15:12:30 taca Exp $
#

DISTNAME=	mecab-naist-jdic-0.6.3-20100801
PKGNAME=	${DISTNAME:S/naist-jdic/naistjdic/}
PKGREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=naist-jdic/48487/}

MAINTAINER=	pkgsrc-userse@NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/naist-jdic/wiki/FrontPage

COMMENT=	Japanese Morphological Dictionary for MeCab
LICENSE=	modified-bsd

BUILD_DEPENDS+=	mecab-base-[0-9]*:../../textproc/mecab-base

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-charset=${MECAB_CHARSET:Q}

BUILD_DEFS+=		MECAB_CHARSET

UNLIMIT_RESOURCES=	datasize

FIND_PREFIX:=	MECABDIR=mecab-base
.include "../../mk/find-prefix.mk"
CONFIGURE_ARGS+=	--with-mecab-config=${MECABDIR}/bin/mecab-config

.include "../../mk/bsd.pkg.mk"
