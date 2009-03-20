# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:39 jlam Exp $

BUILDLINK_TREE+=	psiconv

.if !defined(PSICONV_BUILDLINK3_MK)
PSICONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.psiconv+=	psiconv>=0.8.3nb1
BUILDLINK_ABI_DEPENDS.psiconv+=	psiconv>=0.9.6nb1
BUILDLINK_PKGSRCDIR.psiconv?=	../../converters/psiconv
.endif # PSICONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-psiconv
