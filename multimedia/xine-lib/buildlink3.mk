# $NetBSD: buildlink3.mk,v 1.21 2007/02/07 20:04:00 drochner Exp $

BUILDLINK_TREE+=	xine-lib

.if !defined(XINE_LIB_BUILDLINK3_MK)
XINE_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xine-lib+=	xine-lib>=1rc3c
BUILDLINK_ABI_DEPENDS.xine-lib+=xine-lib>=1.0.3a
BUILDLINK_ABI_DEPENDS.xine-lib?=	xine-lib>=1.1.3nb1
BUILDLINK_PKGSRCDIR.xine-lib?=	../../multimedia/xine-lib
.endif # XINE_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-xine-lib
