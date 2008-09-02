# $NetBSD: Makefile,v 1.16 2007/11/17 12:04:13 rillig Exp $

DISTNAME=	eukleides.1.0.3
PKGNAME=	eukleides-1.0.3
CATEGORIES=	math
MASTER_SITES=	http://www.eukleides.org/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://www.eukleides.org/
COMMENT=	Euclidean geometry drawing language

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	pstoedit>=3.31:../../graphics/pstoedit

BUILD_TARGET=	eukleides
USE_TOOLS+=	bash:run bison gmake makeinfo lex
INFO_FILES=	yes

REPLACE_BASH=	euk2edit euk2eps

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			PREFIX=${DESTDIR}${PREFIX}			\
			BINPATH=${DESTDIR}${PREFIX}/bin			\
			INFODIR=${DESTDIR}${PREFIX}/${PKGINFODIR}	\
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
