# $NetBSD: Makefile,v 1.13 2011/12/03 03:44:38 sbd Exp $
#

DISTNAME=	xapian-core-1.2.8
PKGNAME=	${DISTNAME:S/-core//}
CATEGORIES=	textproc
MASTER_SITES=	http://oligarchy.co.uk/xapian/1.2.8/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://xapian.org/
COMMENT=	Search engine based on Probabilistic Information Retrieval
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

TEST_TARGET=	check

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
