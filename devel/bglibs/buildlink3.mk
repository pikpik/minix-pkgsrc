# $NetBSD: buildlink3.mk,v 1.12 2008/04/12 20:56:25 schmonz Exp $

BUILDLINK_TREE+=	bglibs

.if !defined(BGLIBS_BUILDLINK3_MK)
BGLIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bglibs+=	bglibs>=1.104
BUILDLINK_PKGSRCDIR.bglibs?=	../../devel/bglibs
.endif # BGLIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-bglibs
