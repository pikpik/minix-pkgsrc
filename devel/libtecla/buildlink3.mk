# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:46 jlam Exp $

BUILDLINK_TREE+=	libtecla

.if !defined(LIBTECLA_BUILDLINK3_MK)
LIBTECLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtecla+=	libtecla>=1.5.0
BUILDLINK_ABI_DEPENDS.libtecla?=	libtecla>=1.6.1nb1
BUILDLINK_PKGSRCDIR.libtecla?=	../../devel/libtecla
.endif # LIBTECLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtecla
