# $NetBSD$
#
# This Makefile fragment is included by packages that use tremor.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TREMOR_BUILDLINK3_MK:=	${TREMOR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tremor
.endif

.if !empty(TREMOR_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			tremor
BUILDLINK_DEPENDS.tremor+=		tremor>=1.0.2
BUILDLINK_PKGSRCDIR.tremor?=		../../audio/tremor

.endif # TREMOR_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
