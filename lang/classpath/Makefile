# $NetBSD: Makefile,v 1.10 2006/04/05 06:27:41 jlam Exp $

.include "Makefile.common"

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--disable-gtk-peer

.include "../../mk/bsd.pkg.mk"
