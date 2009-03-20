# $NetBSD: buildlink3.mk,v 1.10 2007/01/07 12:25:51 wiz Exp $

BUILDLINK_TREE+=	libsamplerate

.if !defined(LIBSAMPLERATE_BUILDLINK3_MK)
LIBSAMPLERATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsamplerate+=	libsamplerate>=0.0.13nb1
BUILDLINK_ABI_DEPENDS.libsamplerate+=	libsamplerate>=0.1.2nb3
BUILDLINK_PKGSRCDIR.libsamplerate?=	../../audio/libsamplerate

.include "../../audio/libsndfile/buildlink3.mk"
.endif # LIBSAMPLERATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsamplerate
