# $NetBSD: Makefile,v 1.1.1.1 2000/03/28 00:33:37 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-share-/}

BUILD_DEPENDS+=		${LOCALBASE}/include/libintl.h:../../devel/gettext

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no
CPPFLAGS+=		-I${LOCALBASE}/include		# libintl.h

.include "../../games/freeciv-share/Makefile.common"
