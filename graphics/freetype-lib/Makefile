# $NetBSD: Makefile,v 1.5 2001/05/28 03:16:44 jlam Exp $

PKGNAME=		freetype-lib-${FT_VERS}
COMMENT=		TrueType font rendering engine and library API

CONFIGURE_ARGS+=	--without-x

USE_BUILDLINK_ONLY=	# defined
ALL_TARGET=		ttlib ttpo
INSTALL_TARGET=		install-ttlib install-ttpo

.include "Makefile.common"
