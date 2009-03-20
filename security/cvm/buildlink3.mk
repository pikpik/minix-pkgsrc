# $NetBSD: buildlink3.mk,v 1.8 2008/04/13 06:51:19 schmonz Exp $

BUILDLINK_TREE+=	cvm

.if !defined(CVM_BUILDLINK3_MK)
CVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cvm+=		cvm>=0.90
BUILDLINK_PKGSRCDIR.cvm?=	../../security/cvm
BUILDLINK_DEPMETHOD.cvm?=	build
.endif # CVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-cvm
