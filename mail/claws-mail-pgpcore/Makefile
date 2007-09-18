# $NetBSD: Makefile,v 1.2 2007/08/06 21:41:22 smb Exp $
#

PLUGIN_NAME=	pgpcore
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Handles core PGP functions

PLIST_SRC+=	PLIST

PLIST_SRC+=	PLIST

CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-pgpcore-plugin
CONFIGURE_ARGS+=	--enable-pgpmime-plugin
CONFIGURE_ARGS+=	--enable-pgpinline-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}:../../mail/claws-mail
DEPENDS+=	gnupg>=1.4.7:../../security/gnupg
DEPENDS+=	gpgme>=1.1.4:../../security/gpgme

.include "../../mail/claws-mail/Makefile.vers"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
