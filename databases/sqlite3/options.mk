# $NetBSD: options.mk,v 1.3 2010/12/17 00:37:34 agc Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sqlite3
PKG_SUPPORTED_OPTIONS=		fts icu rtree

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfts)
CFLAGS+=	-DSQLITE_ENABLE_FTS3=1 -DSQLITE_ENABLE_FTS3_PARENTHESIS=1
.endif

.if !empty(PKG_OPTIONS:Micu)
CFLAGS+=	-DSQLITE_ENABLE_ICU=1
LDFLAGS+=	-licui18n -licuuc -licudata
.include "../../textproc/icu/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mrtree)
CFLAGS+=	-DSQLITE_ENABLE_RTREE=1
.endif
