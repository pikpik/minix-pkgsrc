# $NetBSD: buildlink3.mk,v 1.18 2006/07/08 23:11:10 jlam Exp $

BUILDLINK_TREE+=	expat

.if !defined(EXPAT_BUILDLINK3_MK)
EXPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.expat+=	expat>=1.95.7
BUILDLINK_ABI_DEPENDS.expat+=	expat>=2.0.0nb1
BUILDLINK_PKGSRCDIR.expat?=	../../textproc/expat
.endif # EXPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-expat
