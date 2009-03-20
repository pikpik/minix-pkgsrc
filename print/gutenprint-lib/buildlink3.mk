# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/01/11 12:39:47 gdt Exp $

BUILDLINK_TREE+=	gutenprint-lib

.if !defined(GUTENPRINT_LIB_BUILDLINK3_MK)
GUTENPRINT_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gutenprint-lib+=	gutenprint-lib>=5.0.1
BUILDLINK_PKGSRCDIR.gutenprint-lib?=	../../print/gutenprint-lib
.endif # GUTENPRINT_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-gutenprint-lib
