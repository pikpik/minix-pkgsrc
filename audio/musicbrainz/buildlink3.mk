# $NetBSD$

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBMUSICBRAINZ_BUILDLINK3_MK:=	${LIBMUSICBRAINZ_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmusicbrainz
.endif

.if !empty(LIBMUSICBRAINZ_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libmusicbrainz
BUILDLINK_DEPENDS.libmusicbrainz?=		libmusicbrainz>=2.0.2
BUILDLINK_PKGSRCDIR.libmusicbrainz?=		../../audio/libmusicbrainz

.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"

.endif # LIBMUSICBRAINZ_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
