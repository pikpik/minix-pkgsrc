# $NetBSD$

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENBOX_BUILDLINK3_MK:=	${OPENBOX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openbox
.endif

.if !empty(OPENBOX_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			openbox
BUILDLINK_DEPENDS.openbox+=		openbox>=3.1
BUILDLINK_PKGSRCDIR.openbox?=		../../wm/openbox

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.endif # OPENBOX_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
