# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:45 jlam Exp $

BUILDLINK_TREE+=	librsync

.if !defined(LIBRSYNC_BUILDLINK3_MK)
LIBRSYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librsync+=	librsync>=0.9.6nb2
BUILDLINK_ABI_DEPENDS.librsync+=	librsync>=0.9.7nb1
BUILDLINK_PKGSRCDIR.librsync?=	../../devel/librsync

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # LIBRSYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-librsync
