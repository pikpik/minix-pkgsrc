# $NetBSD$
#

DISTNAME=	artist-1.2.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.lysator.liu.se/~tab/artist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.lysator.liu.se/~tab/artist/
COMMENT=	Elisp drawing package with mouse and keyboard support

DEPENDS+=	emacs>=19.29:../../editors/emacs

GNU_CONFIGURE=	YES

DOCS=		BUGS COPYING ChangeLog INSTALL README TODO
DOCDIR=		${PREFIX}/share/doc/artist

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
