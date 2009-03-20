# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/05/15 20:06:03 drochner Exp $

BUILDLINK_TREE+=	pdflib-lite

.if !defined(PDFLIB_LITE_BUILDLINK3_MK)
PDFLIB_LITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pdflib-lite+=	pdflib-lite>=7.0.3
BUILDLINK_PKGSRCDIR.pdflib-lite?=	../../print/pdflib-lite
.endif # PDFLIB_LITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pdflib-lite
