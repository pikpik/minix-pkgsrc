# $NetBSD: Makefile,v 1.1.1.1 2001/04/16 22:23:34 zuntum Exp $
#

DISTNAME=	shorten-3.5.0
CATEGORIES=	audio archivers
MASTER_SITES=	http://www.etree.org/shnutils/shorten/source/

MAINTAINER=	collver@linuxfreemail.com
HOMEPAGE=	http://www.etree.org/shnutils/shorten/
COMMENT=	lossless audio compressor

LICENSE=	no-commercial-use

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/shorten
	${INSTALL_DATA} ${WRKSRC}/doc/tr156.tex ${PREFIX}/share/doc/shorten
	${INSTALL_DATA} ${WRKSRC}/doc/tr156.ps ${PREFIX}/share/doc/shorten

.include "../../mk/bsd.pkg.mk"
