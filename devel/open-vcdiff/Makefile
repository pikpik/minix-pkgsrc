# $NetBSD: Makefile,v 1.2 2012/10/31 11:16:34 asau Exp $
#

DISTNAME=	open-vcdiff-0.8.3
CATEGORIES=	devel
MASTER_SITES=	http://open-vcdiff.googlecode.com/files/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://code.google.com/p/open-vcdiff/
COMMENT=	RFC 3284 encoder/decoder for VCDIFF Differencing and Compression
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++

AUTO_MKDIRS=	yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
