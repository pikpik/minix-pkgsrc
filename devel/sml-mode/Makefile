# $NetBSD: Makefile,v 1.7 2003/08/09 10:44:50 seb Exp $

DISTNAME=	sml-mode-3.9.5
CATEGORIES=	devel editors
MASTER_SITES=	ftp://flint.cs.yale.edu/pub/monnier/sml-mode/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Emacs mode for editing Standard ML source code

ALL_TARGET=	default

INFO_FILES=	sml-mode.info

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/sml-mode
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc README NEWS TODO \
		ChangeLog ${EMACS_LISPPREFIX}/sml-mode
	${INSTALL_DATA} ${WRKSRC}/sml-mode.info ${PREFIX}/info

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
