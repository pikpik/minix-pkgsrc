# $NetBSD$
#
# This Makefile fragment is included by packages that use lablgtk.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LABLGTK_BUILDLINK3_MK:=	${LABLGTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	lablgtk
.endif

.if !empty(LABLGTK_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			lablgtk
BUILDLINK_DEPENDS.lablgtk+=		lablgtk>=1.2.5nb3
BUILDLINK_PKGSRCDIR.lablgtk?=		../../x11/lablgtk

.include "../../x11/gtk/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"

.endif # LABLGTK_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
