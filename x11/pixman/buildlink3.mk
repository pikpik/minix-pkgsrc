# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/11/08 19:51:43 bjs Exp $

BUILDLINK_TREE+=	pixman

.if !defined(PIXMAN_BUILDLINK3_MK)
PIXMAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pixman+=	pixman>=0.9.6
BUILDLINK_PKGSRCDIR.pixman?=	../../x11/pixman
.endif # PIXMAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-pixman
