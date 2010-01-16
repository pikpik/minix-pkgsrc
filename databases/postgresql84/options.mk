# $NetBSD: options.mk,v 1.1.1.1 2009/07/29 06:26:17 adam Exp $

PKG_SUPPORTED_OPTIONS+=		# empty

.include "../../mk/bsd.options.mk"

###
### LDAP authentication for the PostgreSQL backend.
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
.endif

###
### PAM authentication for the PostgreSQL backend.
###
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif
