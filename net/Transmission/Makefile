# $NetBSD: Makefile,v 1.77 2012/01/13 10:55:25 obache Exp $

PKGNAME=		${DISTNAME:C:t:T:}
PKGREVISION=		3

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--without-gtk

.include "../../net/Transmission/Makefile.common"

.include "../../mk/bsd.pkg.mk"
