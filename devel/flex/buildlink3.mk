# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:42 jlam Exp $
#

BUILDLINK_TREE+=	flex

.if !defined(FLEX_BUILDLINK3_MK)
FLEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flex+=	flex>=2.5.4a
BUILDLINK_PKGSRCDIR.flex?=	../../devel/flex
BUILDLINK_DEPMETHOD.flex?=	build
.endif # FLEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-flex
