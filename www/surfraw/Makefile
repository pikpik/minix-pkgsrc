# $NetBSD: Makefile,v 1.5 2000/08/12 12:16:03 proff Exp $
#

DISTNAME=	surfraw-1.0.2
CATEGORIES=	www
MASTER_SITES=	http://download.sourceforge.net/surfraw/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://surfraw.sourceforge.net/

CONFLICTS+=	surfaw-*

GNU_CONFIGURE=	# defined

DOCDIR=		${PREFIX}/share/doc/surfraw

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
