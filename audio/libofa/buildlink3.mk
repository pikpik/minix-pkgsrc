# $NetBSD$

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBOFA_BUILDLINK3_MK:=	${LIBOFA_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libofa
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibofa}
BUILDLINK_PACKAGES+=	libofa
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libofa

.if ${LIBOFA_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libofa+=	libofa>=0.9.3
BUILDLINK_PKGSRCDIR.libofa?=	../../audio/libofa
.endif	# LIBOFA_BUILDLINK3_MK

.include "../../math/fftw/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
