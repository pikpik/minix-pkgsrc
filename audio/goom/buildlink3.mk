# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:36 jlam Exp $

BUILDLINK_TREE+=	goom

.if !defined(GOOM_BUILDLINK3_MK)
GOOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.goom+=	goom>=2004.0
BUILDLINK_PKGSRCDIR.goom?=	../../audio/goom
.endif # GOOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-goom
