# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 04:06:04 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XERCES_C_BUILDLINK3_MK:=	${XERCES_C_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xerces-c
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxerces-c}
BUILDLINK_PACKAGES+=	xerces-c

.if !empty(XERCES_C_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xerces-c+=	xerces-c>=2.3.0
BUILDLINK_PKGSRCDIR.xerces-c?=	../../textproc/xerces-c

.include "../../converters/libiconv/buildlink3.mk"

.endif	# XERCES_C_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
