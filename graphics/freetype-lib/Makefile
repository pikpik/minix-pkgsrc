# $NetBSD: Makefile,v 1.6 2001/09/09 03:37:00 jlam Exp $

PKGNAME=		freetype-lib-${FT_VERS}
COMMENT=		TrueType font rendering engine and library API

USE_BUILDLINK_ONLY=	# defined
CONFIGURE_ARGS+=	--without-x

.include "Makefile.common"

ALL_TARGET=		ttlib ttpo
INSTALL_TARGET=		install-ttlib install-ttpo

.include "../../mk/bsd.pkg.mk"
