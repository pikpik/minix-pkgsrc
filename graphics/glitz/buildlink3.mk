# $NetBSD: buildlink3.mk,v 1.11 2006/07/23 01:24:38 minskim Exp $

BUILDLINK_TREE+=	glitz

.if !defined(GLITZ_BUILDLINK3_MK)
GLITZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glitz+=	glitz>=0.4.4
BUILDLINK_ABI_DEPENDS.glitz+=	glitz>=0.4.4nb2
BUILDLINK_PKGSRCDIR.glitz?=	../../graphics/glitz
.endif # GLITZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-glitz
