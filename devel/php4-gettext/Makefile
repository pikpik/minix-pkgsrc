# $NetBSD: Makefile,v 1.3 2001/12/03 08:31:00 jlam Exp $

MODNAME=		gettext
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for gettext support

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
