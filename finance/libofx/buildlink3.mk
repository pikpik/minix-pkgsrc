# $NetBSD: buildlink3.mk,v 1.7 2006/09/03 13:02:17 wiz Exp $

BUILDLINK_TREE+=	libofx

.if !defined(LIBOFX_BUILDLINK3_MK)
LIBOFX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libofx+=	libofx>=0.8.0
BUILDLINK_PKGSRCDIR.libofx?=	../../finance/libofx
BUILDLINK_INCDIRS.libofx+=	include/libofx

.include "../../textproc/opensp/buildlink3.mk"
.endif # LIBOFX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libofx
