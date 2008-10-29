# $NetBSD: options.mk,v 1.1 2007/09/20 20:50:50 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.balsa
PKG_SUPPORTED_OPTIONS=	compface ldap sqlite ssl
PKG_SUGGESTED_OPTIONS=	compface ldap sqlite ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcompface)
CONFIGURE_ARGS+=	--with-compface
.  include "../../graphics/compface/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--with-sqlite
.  include "../../databases/sqlite3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
.  include "../../security/openssl/buildlink3.mk"
.endif
