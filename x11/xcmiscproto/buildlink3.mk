# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 17:50:36 joerg Exp $

BUILDLINK_DEPMETHOD.xcmiscproto?=	build

BUILDLINK_TREE+=	xcmiscproto

.if !defined(XCMISCPROTO_BUILDLINK3_MK)
XCMISCPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcmiscproto+=	xcmiscproto>=1.1
BUILDLINK_PKGSRCDIR.xcmiscproto?=	../../x11/xcmiscproto
.endif # XCMISCPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcmiscproto
