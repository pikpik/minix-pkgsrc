# $NetBSD: Makefile,v 1.4 2001/02/16 15:10:49 wiz Exp $

.include "../../games/freeciv-share/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-share-/}
COMMENT=		Machine independent files for Freeciv

USE_BUILDLINK_ONLY=	# defined

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no

.include "../../mk/bsd.pkg.mk"
