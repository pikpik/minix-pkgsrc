# $NetBSD: Makefile,v 1.9 2004/04/25 00:18:14 xtraeme Exp $

MODNAME=		ftp
PKGREVISION=		# empty
CATEGORIES+=		net
COMMENT=		PHP extension for FTP access

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--enable-${MODNAME}

# adjust so that the pkg gets built with SSL support
LIBS+=			-lssl -lcrypto
CFLAGS+=		-DHAVE_OPENSSL_EXT

.include "../../lang/php/ext.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
