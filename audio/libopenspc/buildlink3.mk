# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/01/26 16:44:00 drochner Exp $

BUILDLINK_TREE+=	libopenspc

.if !defined(LIBOPENSPC_BUILDLINK3_MK)
LIBOPENSPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopenspc+=	libopenspc>=0.3.99.20050926
BUILDLINK_PKGSRCDIR.libopenspc?=	../../audio/libopenspc
.endif # LIBOPENSPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopenspc
