# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:47 jlam Exp $

BUILDLINK_TREE+=	pccts

.if !defined(PCCTS_BUILDLINK3_MK)
PCCTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pccts+=	pccts>=1.33.22
BUILDLINK_ABI_DEPENDS.pccts?=	pccts>=1.33.22nb1
BUILDLINK_PKGSRCDIR.pccts?=	../../devel/pccts
BUILDLINK_DEPMETHOD.pccts?=	build
.endif # PCCTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pccts
