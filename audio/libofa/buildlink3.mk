# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/07/12 13:12:57 wiz Exp $

BUILDLINK_TREE+=	libofa

.if !defined(LIBOFA_BUILDLINK3_MK)
LIBOFA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libofa+=	libofa>=0.9.3
BUILDLINK_PKGSRCDIR.libofa?=	../../audio/libofa

.include "../../math/fftw/buildlink3.mk"
.endif # LIBOFA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libofa
