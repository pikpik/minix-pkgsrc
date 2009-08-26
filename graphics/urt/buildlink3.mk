# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:45 joerg Exp $

BUILDLINK_TREE+=	urt

.if !defined(URT_BUILDLINK3_MK)
URT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.urt+=	urt>=3.1b1nb5
BUILDLINK_ABI_DEPENDS.urt+=	urt>=3.1b1nb9
BUILDLINK_PKGSRCDIR.urt?=	../../graphics/urt

.include "../../graphics/netpbm/buildlink3.mk"
.endif # URT_BUILDLINK3_MK

BUILDLINK_TREE+=	-urt
