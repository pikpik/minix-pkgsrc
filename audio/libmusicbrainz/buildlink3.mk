# $NetBSD: buildlink3.mk,v 1.3 2008/01/18 05:06:20 tnn Exp $

BUILDLINK_TREE+=	libmusicbrainz

.if !defined(LIBMUSICBRAINZ_BUILDLINK3_MK)
LIBMUSICBRAINZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmusicbrainz+=	libmusicbrainz>=3.0.0
BUILDLINK_ABI_DEPENDS.libmusicbrainz?=	libmusicbrainz>=3.0.0nb1
BUILDLINK_PKGSRCDIR.libmusicbrainz?=	../../audio/libmusicbrainz

.include "../../www/neon/buildlink3.mk"
.endif # LIBMUSICBRAINZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmusicbrainz
