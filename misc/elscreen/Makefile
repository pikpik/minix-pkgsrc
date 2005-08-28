# $NetBSD: Makefile,v 1.1.1.1 2004/12/01 03:49:40 uebayasi Exp $
#

DISTNAME=	elscreen-1.3.2
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.morishima.net/pub/morishima.net/naoto/ElScreen/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.morishima.net/~naoto/j/software/elscreen/
COMMENT=	Window manager within Emacs

NO_BUILD=	# Defined

do-install:
	@${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/elscreen
	@${INSTALL_DATA} ${WRKSRC}/elscreen.el ${EMACS_LISPPREFIX}/elscreen

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
