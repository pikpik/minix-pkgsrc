# $NetBSD: Makefile,v 1.16 2006/07/19 19:14:39 jlam Exp $
#

DISTNAME=		chasen-${CHASEN_VERSION}
PKGNAME=		chasen-base-${CHASEN_VERSION}
CATEGORIES=		japanese textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_JP:=chasen-legacy/26168/}

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://chasen-legacy.sourceforge.jp/
COMMENT=		ChaSen, Japanese Morphological Analysis System

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
OWN_DIRS=		${PREFIX}/${CHASEN_DICDIR}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../textproc/chasen/Makefile.common"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/darts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
