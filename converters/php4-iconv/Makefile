# $NetBSD$

MODNAME=		iconv
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for character set conversion

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-iconv=shared,${BUILDLINK_PREFIX.iconv}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
