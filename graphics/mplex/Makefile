# $NetBSD$

DISTNAME=	mplex-1.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/general/graphics/mpeg/mplex/

MAINTAINER=	collver@linuxfreemail.com
COMMENT=	Multiplexes MPEG component streams into system layers

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplex ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mplex
	for FILE in COPYING INSTRUCT README; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${PREFIX}/share/doc/mplex; \
	done

.include "../../mk/bsd.pkg.mk"
