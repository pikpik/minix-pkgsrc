# $NetBSD$
#

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
PKG_DEFAULT_OPTIONS+=	openldap
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.balsa2
PKG_SUPPORTED_OPTIONS=	openldap ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenldap)
CONFIGURE_ARGS+=        --with-ldap
.  include "../../databases/openldap/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
.  include "../../security/openssl/buildlink3.mk"
.endif
