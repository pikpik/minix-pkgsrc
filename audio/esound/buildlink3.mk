# $NetBSD: buildlink3.mk,v 1.5 2004/03/05 19:25:06 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ESOUND_BUILDLINK3_MK:=	${ESOUND_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	esound
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nesound}
BUILDLINK_PACKAGES+=	esound

.if !empty(ESOUND_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.esound+=	esound>=0.2.18
BUILDLINK_PKGSRCDIR.esound?=	../../audio/esound
.endif	# ESOUND_BUILDLINK3_MK

.include "../../audio/libaudiofile/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
