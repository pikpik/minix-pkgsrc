# $NetBSD: buildlink3.mk,v 1.1 2007/02/01 19:07:24 drochner Exp $

BUILDLINK_TREE+=	check

.if !defined(CHECK_BUILDLINK3_MK)
CHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.check+=	check>=0.9.5
BUILDLINK_PKGSRCDIR.check?=	../../devel/check
.endif # CHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-check
