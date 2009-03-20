# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 22:03:23 joerg Exp $

BUILDLINK_DEPMETHOD.resourceproto?=	build

BUILDLINK_TREE+=	resourceproto

.if !defined(RESOURCEPROTO_BUILDLINK3_MK)
RESOURCEPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.resourceproto+=	resourceproto>=1.0.1
BUILDLINK_PKGSRCDIR.resourceproto?=	../../x11/resourceproto
.endif # RESOURCEPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-resourceproto
