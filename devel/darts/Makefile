# $NetBSD: Makefile,v 1.4 2006/03/04 21:29:14 jlam Exp $

DISTNAME=	darts-0.31
CATEGORIES=	devel
MASTER_SITES=	http://chasen.org/~taku/software/darts/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://chasen.org/~taku/software/darts/
COMMENT=	C++ template library that implements Double-Array

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

DOCDIR=		share/doc/darts
EXAMPLESDIR=	share/examples/darts
HTMLDOCDIR=	share/doc/html/darts
DOCS=		AUTHORS ChangeLog README
EXAMPLES=	darts.cpp mkdarts.cpp
HTMLDOCS=	darts.css index.html

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${DOCDIR} ${EXAMPLESDIR} ${HTMLDOCDIR}

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor
.for f in ${HTMLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/${HTMLDOCDIR}
.endfor
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${EXAMPLESDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
