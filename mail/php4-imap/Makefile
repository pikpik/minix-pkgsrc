# $NetBSD: Makefile,v 1.6 2002/02/28 06:18:03 jlam Exp $

MODNAME=		imap
CATEGORIES+=		mail
PKGREVISION=		# empty
COMMENT=		PHP4 extension for IMAP (Internet Mailbox Access Protocol)

USE_BUILDLINK2=		# defined

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.imap-uw}
CONFIGURE_ARGS+=	--with-${MODNAME}-ssl=${SSLBASE}
CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no

LIBS+=			-lssl -lcrypto

.include "../../mail/imap-uw/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
