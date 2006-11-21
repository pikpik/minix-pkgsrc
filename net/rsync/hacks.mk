# $NetBSD: hacks.mk,v 1.1 2006/04/10 13:26:15 schwarz Exp $

### [Tue Nov 21 19:32:00 UTC 2006 : tvierling]
### iconv(..., NULL, 0, NULL, 0) crashes in libc version of iconv(3)
###
.if !empty(LOWER_OPSYS:Minterix*)
PKG_HACKS+=	pkgsrc-iconv
.include "../../converters/libiconv/buildlink3.mk"
.endif
