# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:59 jlam Exp $

BUILDLINK_TREE+=	fftwf

.if !defined(FFTWF_BUILDLINK3_MK)
FFTWF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fftwf+=	fftwf>=3.0
BUILDLINK_ABI_DEPENDS.fftwf+=	fftwf>=3.0.1nb1
BUILDLINK_PKGSRCDIR.fftwf?=	../../math/fftwf

.include "../../math/fftw/buildlink3.mk"
.endif # FFTWF_BUILDLINK3_MK

BUILDLINK_TREE+=	-fftwf
