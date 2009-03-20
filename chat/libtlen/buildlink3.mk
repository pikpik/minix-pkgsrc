# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:38 jlam Exp $

BUILDLINK_TREE+=	libtlen

.if !defined(LIBTLEN_BUILDLINK3_MK)
LIBTLEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtlen+=	libtlen>=20040212
BUILDLINK_ABI_DEPENDS.libtlen+=	libtlen>=20040212nb1
BUILDLINK_PKGSRCDIR.libtlen?=	../../chat/libtlen
.endif # LIBTLEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtlen
