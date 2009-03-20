# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:59 jlam Exp $

BUILDLINK_TREE+=	fftw

.if !defined(FFTW_BUILDLINK3_MK)
FFTW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fftw+=	fftw>=3.0
BUILDLINK_ABI_DEPENDS.fftw+=	fftw>=3.1nb1
BUILDLINK_PKGSRCDIR.fftw?=	../../math/fftw
.endif # FFTW_BUILDLINK3_MK

BUILDLINK_TREE+=	-fftw
