# $NetBSD$
#
# This Makefile fragment is included by packages that use xerces-c.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XERCES_C_BUILDLINK3_MK:=	${XERCES_C_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xerces-c
.endif

.if !empty(XERCES_C_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			xerces-c
BUILDLINK_DEPENDS.xerces-c+=		xerces-c>=2.3.0
BUILDLINK_PKGSRCDIR.xerces-c?=		../../textproc/xerces-c

.include "../../converters/libiconv/buildlink3.mk"

.endif # XERCES_C_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
