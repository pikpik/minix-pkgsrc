# $NetBSD: Makefile,v 1.16 2004/07/06 19:52:01 jdolecek Exp $

MODNAME=		imap
PKGREVISION=		# empty
CATEGORIES+=		mail
COMMENT=		PHP extension for IMAP (Internet Mailbox Access Protocol)

USE_BUILDLINK3=		YES
USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.imap-uw}
CONFIGURE_ARGS+=	--with-${MODNAME}-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-${MODNAME}-linkage
CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no

LIBS+=			-lssl -lcrypto

.include "../../lang/php/ext.mk"
.include "../../mail/imap-uw/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
