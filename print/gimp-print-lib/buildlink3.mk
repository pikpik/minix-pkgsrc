# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:11:05 jlam Exp $

BUILDLINK_TREE+=	gimp-print-lib

.if !defined(GIMP_PRINT_LIB_BUILDLINK3_MK)
GIMP_PRINT_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gimp-print-lib+=	gimp-print-lib>=4.2.5nb1
BUILDLINK_ABI_DEPENDS.gimp-print-lib+=	gimp-print-lib>=4.2.7nb2
BUILDLINK_PKGSRCDIR.gimp-print-lib?=	../../print/gimp-print-lib

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # GIMP_PRINT_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-gimp-print-lib
