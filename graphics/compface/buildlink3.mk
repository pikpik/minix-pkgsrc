# $NetBSD$
#
# This Makefile fragment is included by packages that use compface.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
COMPFACE_BUILDLINK3_MK:=	${COMPFACE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	compface
.endif

.if !empty(COMPFACE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			compface
BUILDLINK_DEPENDS.compface+=		compface>=1.4
BUILDLINK_PKGSRCDIR.compface?=		../../graphics/compface

.endif # COMPFACE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
