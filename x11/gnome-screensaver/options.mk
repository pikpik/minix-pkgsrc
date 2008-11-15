# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-screensaver
PKG_SUPPORTED_OPTIONS=	pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
. include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pam
. include "../../mk/bsd.prefs.mk"
.  if ${OPSYS} == "NetBSD"
# needed to read shadow passwords
DEPENDS+=	pam-pwauth_suid-[0-9]*:../../security/pam-pwauth_suid
.  endif
.else
CONFIGURE_ARGS+=	--disable-pam
SPECIAL_PERMS+=		libexec/gnome-screensaver-dialog ${SETUID_ROOT_PERMS}
.endif
