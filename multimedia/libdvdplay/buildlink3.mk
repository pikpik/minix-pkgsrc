# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:01 jlam Exp $

BUILDLINK_TREE+=	libdvdplay

.if !defined(LIBDVDPLAY_BUILDLINK3_MK)
LIBDVDPLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdvdplay+=		libdvdplay>=1.0.1
BUILDLINK_ABI_DEPENDS.libdvdplay+=	libdvdplay>=1.0.1nb3
BUILDLINK_PKGSRCDIR.libdvdplay?=	../../multimedia/libdvdplay

.include "../../multimedia/libdvdread/buildlink3.mk"
.endif # LIBDVDPLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdvdplay
