# $NetBSD: options.mk,v 1.2 2007/02/22 19:26:56 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.netatalk1
PKG_SUPPORTED_OPTIONS=	pam
.include "../../mk/bsd.options.mk"

###
### Support PAM authentication and build smbpass and winbind PAM modules.
###
PLIST_VARS+=		pam
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../security/PAM/module.mk"
CONFIGURE_ARGS+=	--with-pam
PLIST.pam=		yes
.else
CONFIGURE_ARGS+=	--without-pam
.endif
