# $NetBSD: buildlink3.mk,v 1.7 2007/01/03 07:03:15 wiz Exp $

BUILDLINK_TREE+=	openal

.if !defined(OPENAL_BUILDLINK3_MK)
OPENAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openal+=	openal>=0.0.8
BUILDLINK_PKGSRCDIR.openal?=	../../audio/openal
.endif # OPENAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-openal
