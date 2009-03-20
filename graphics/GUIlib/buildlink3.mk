# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:10:50 jlam Exp $

BUILDLINK_TREE+=	GUIlib

.if !defined(GUILIB_BUILDLINK3_MK)
GUILIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.GUIlib+=	GUIlib>=1.1.0nb2
BUILDLINK_ABI_DEPENDS.GUIlib+=	GUIlib>=1.1.0nb7
BUILDLINK_PKGSRCDIR.GUIlib?=	../../graphics/GUIlib

.include "../../devel/SDL/buildlink3.mk"
.endif # GUILIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-GUIlib
