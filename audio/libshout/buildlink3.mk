# $NetBSD$

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSHOUT_BUILDLINK3_MK:=	${LIBSHOUT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libshout
.endif

.if !empty(LIBSHOUT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		libshout
BUILDLINK_DEPENDS.libshout+=	libshout>=2.0
BUILDLINK_PKGSRCDIR.libshout?=	../../audio/libshout

.  include "../../audio/libvorbis/buildlink3.mk"
.  include "../../mk/pthread.buildlink3.mk"
.endif # LIBSHOUT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
