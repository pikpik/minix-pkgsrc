# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:45 jlam Exp $

BUILDLINK_TREE+=	liboil

.if !defined(LIBOIL_BUILDLINK3_MK)
LIBOIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboil+=	liboil>=0.3.6
BUILDLINK_PKGSRCDIR.liboil?=	../../devel/liboil
.endif # LIBOIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboil
