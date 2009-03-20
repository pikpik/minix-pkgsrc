# $NetBSD: buildlink3.mk,v 1.2 2006/11/03 17:24:25 joerg Exp $

BUILDLINK_TREE+=	libFS

.if !defined(LIBFS_BUILDLINK3_MK)
LIBFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libFS+=	libFS>=1.0.0
BUILDLINK_PKGSRCDIR.libFS?=	../../x11/libFS

.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # LIBFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libFS
