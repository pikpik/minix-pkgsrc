# $NetBSD$

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXML2_BUILDLINK3_MK:=	${LIBXML2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxml2
.endif

.if !empty(LIBXML2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		libxml2
BUILDLINK_DEPENDS.libxml2?=	libxml2>=2.6.2
BUILDLINK_PKGSRCDIR.libxml2?=	../../textproc/libxml2

.  include "../../devel/zlib/buildlink3.mk"
.  include "../../converters/libiconv/buildlink3.mk"
.endif # LIBXML2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
