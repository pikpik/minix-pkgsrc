# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:11:06 jlam Exp $

BUILDLINK_TREE+=	dirmngr

.if !defined(DIRMNGR_BUILDLINK3_MK)
DIRMNGR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dirmngr+=	dirmngr>=0.9.3nb1
BUILDLINK_ABI_DEPENDS.dirmngr?=	dirmngr>=0.9.3nb2
BUILDLINK_PKGSRCDIR.dirmngr?=	../../security/dirmngr
.endif # DIRMNGR_BUILDLINK3_MK

BUILDLINK_TREE+=	-dirmngr
