# $NetBSD: options.mk,v 1.4 2007/02/22 19:26:44 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.spamprobe
PKG_SUPPORTED_OPTIONS=		bdb gif png jpeg
PKG_SUGGESTED_OPTIONS=		gif png jpeg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbdb)
BDB_ACCEPTED=		db4 # db3 db2 (not tested)
.include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--with-db=${BDBBASE:Q}
.endif

.if !empty(PKG_OPTIONS:Mgif)
.include "../../graphics/libungif/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjpg)
.include "../../graphics/jpeg/buildlink3.mk"
.endif
