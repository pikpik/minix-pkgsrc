# $NetBSD: Makefile,v 1.3 2001/12/03 08:31:04 jlam Exp $

MODNAME=		xml
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for parsing XML

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-expat-dir=shared,${BUILDLINK_DIR}

.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
