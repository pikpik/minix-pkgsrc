# $NetBSD: Makefile,v 1.82 2013/02/06 23:23:09 jperkin Exp $

PKGREVISION=		1

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--without-gtk

.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
