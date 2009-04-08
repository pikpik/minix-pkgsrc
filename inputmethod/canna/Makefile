# $NetBSD: Makefile,v 1.9 2008/09/18 12:35:27 taca Exp $

META_PACKAGE=	# empty

.include "Makefile.common"

PKGNAME:=	Canna-${CANNA_VERSION}
PKGREVISION=	2

DEPENDS+=	Canna-server>=${CANNA_VERSION}nb2:../../inputmethod/canna-server
DEPENDS+=	Canna-dict>=${CANNA_VERSION}nb1:../../inputmethod/canna-dict

CANNA_MODULE=	meta-package

.include "../../mk/bsd.pkg.mk"
