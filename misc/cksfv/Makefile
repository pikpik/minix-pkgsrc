# $NetBSD: Makefile,v 1.7 2004/04/25 11:48:31 dillo Exp $
#

DISTNAME=	cksfv-1.3.3
CATEGORIES=	misc
MASTER_SITES=	http://www.modeemi.fi/~shd/foss/cksfv/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.modeemi.fi/~shd/foss/cksfv/
COMMENT=	Check and create simple file verification (SFV) listings

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/man
CONFIGURE_ARGS+=	--compiler=${CC:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cksfv
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cksfv

.include "../../mk/bsd.pkg.mk"
