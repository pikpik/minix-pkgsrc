# $NetBSD$
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GIMP_PRINT_LIB_BUILDLINK3_MK:=	${GIMP_PRINT_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gimp-print-lib
.endif

.if !empty(GIMP_PRINT_LIB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gimp-print-lib
BUILDLINK_DEPENDS.gimp-print-lib+=		gimp-print-lib>=4.2.5nb1
BUILDLINK_PKGSRCDIR.gimp-print-lib?=		../../print/gimp-print-lib

.include "../../devel/gettext-lib/buildlink3.mk"

.endif # GIMP_PRINT_LIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
