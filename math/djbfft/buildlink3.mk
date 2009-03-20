# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:59 jlam Exp $

BUILDLINK_TREE+=	djbfft

.if !defined(DJBFFT_BUILDLINK3_MK)
DJBFFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.djbfft+=	djbfft>=0.76
BUILDLINK_PKGSRCDIR.djbfft?=	../../math/djbfft
BUILDLINK_DEPMETHOD.djbfft?=	build
.endif # DJBFFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-djbfft
