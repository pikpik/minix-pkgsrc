# $NetBSD: buildlink3.mk,v 1.1 2004/02/27 07:37:04 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PNETLIB_BUILDLINK3_MK:=	${PNETLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pnetlib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npnetlib}
BUILDLINK_PACKAGES+=	pnetlib

.if !empty(PNETLIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pnetlib+=	pnetlib>=0.6.2
BUILDLINK_PKGSRCDIR.pnetlib?=	../../lang/pnetlib

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../lang/pnet/buildlink3.mk"

.endif	# PNETLIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
