# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/14 13:30:57 joerg Exp $

BUILDLINK_DEPMETHOD.glproto?=	build

BUILDLINK_TREE+=	glproto

.if !defined(GLPROTO_BUILDLINK3_MK)
GLPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glproto+=	glproto>=1.4.6
BUILDLINK_PKGSRCDIR.glproto?=	../../x11/glproto
.endif # GLPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-glproto
