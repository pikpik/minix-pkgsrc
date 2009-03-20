# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:10 jlam Exp $

BUILDLINK_TREE+=	hre

.if !defined(HRE_BUILDLINK3_MK)
HRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hre+=		hre>=0.9.7
BUILDLINK_ABI_DEPENDS.hre+=	hre>=0.9.8anb1
BUILDLINK_PKGSRCDIR.hre?=	../../textproc/hre
.endif # HRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hre
