# $NetBSD: options.mk,v 1.3 2008/08/08 23:41:22 epg Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.nmh
PKG_SUPPORTED_OPTIONS=		nmh-backup-hash sasl tls

.include "../../mk/bsd.options.mk"

###
### Prepend a "#" instead of a "," to the name of a message that is
### "removed" by rmm.
###
.if !empty(PKG_OPTIONS:Mnmh-backup-hash)
CONFIGURE_ARGS+=	--with-hash-backup
.endif

.if !empty(PKG_OPTIONS:Msasl)
CONFIGURE_ARGS+=	--with-cyrus-sasl
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtls)
CONFIGURE_ARGS+=	--with-tls
.include "../../security/openssl/buildlink3.mk"
.endif
