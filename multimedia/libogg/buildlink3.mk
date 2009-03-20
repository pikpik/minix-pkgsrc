# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:11:02 jlam Exp $
#

BUILDLINK_TREE+=	libogg

.if !defined(LIBOGG_BUILDLINK3_MK)
LIBOGG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libogg+=	libogg>=1.1
BUILDLINK_ABI_DEPENDS.libogg+=	libogg>=1.1.2nb1
BUILDLINK_PKGSRCDIR.libogg?=	../../multimedia/libogg
.endif # LIBOGG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libogg
