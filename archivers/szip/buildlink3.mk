# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:35 jlam Exp $

BUILDLINK_TREE+=	szip

.if !defined(SZIP_BUILDLINK3_MK)
SZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.szip+=	szip>=2.0
BUILDLINK_PKGSRCDIR.szip?=	../../archivers/szip
.endif # SZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-szip
