# $NetBSD: Makefile,v 1.6 2002/06/09 19:01:12 jlam Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

USE_BUILDLINK2=		yes

.include "../../www/php4/Makefile.module"

MCRYPT_DIR=		${BUILDLINK_PREFIX.libmcrypt22}
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MCRYPT_DIR}
CONFIGURE_ENV+=		MCRYPT_DIR="${MCRYPT_DIR}"

.include "../../security/libmcrypt22/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
