# $NetBSD$

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FLAC_BUILDLINK3_MK:=	${FLAC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	flac
.endif

.if !empty(FLAC_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		flac
BUILDLINK_DEPENDS.flac+=	flac>=1.1.0nb1
BUILDLINK_PKGSRCDIR.flac?=	../../audio/flac

.  include "../../audio/libogg/buildlink3.mk"
.endif # FLAC_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
