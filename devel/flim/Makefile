# $NetBSD: Makefile,v 1.2 2001/07/06 02:00:11 jun Exp $

DISTNAME=	flim-1.14.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/flim/flim-1.14/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.m17n.org/FLIM/
COMMENT=	Emacs lisp library for message representation/encoding

DEPENDS+=	apel-10.*:../../devel/apel

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
ALL_TARGET=     elc
INSTALL_TARGET= install
PLIST_SRC=      ${PKGDIR}/PLIST.emacs
.else   # ${EMACS_FLAVOR} == "xemacs"
ALL_TARGET=     package
INSTALL_TARGET= install-package
PLIST_SRC=      ${PKGDIR}/PLIST.xemacs
MAKEFLAGS+=     PACKAGEDIR=${EMACS_LISPPREX:C|/lisp$||}
.endif

.include "../../mk/bsd.pkg.mk"
