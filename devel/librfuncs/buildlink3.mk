# $NetBSD: buildlink3.mk,v 1.9 2007/02/15 14:24:24 rillig Exp $

BUILDLINK_TREE+=	librfuncs

.if !defined(LIBRFUNCS_BUILDLINK3_MK)
LIBRFUNCS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librfuncs+=	librfuncs>=1.0.4
BUILDLINK_PKGSRCDIR.librfuncs?=	../../devel/librfuncs
BUILDLINK_LDFLAGS.librfuncs+=	-lrfuncs
.endif # LIBRFUNCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-librfuncs
