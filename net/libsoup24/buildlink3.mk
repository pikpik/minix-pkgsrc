# $NetBSD: buildlink3.mk,v 1.12 2008/03/06 14:53:53 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSOUP24_BUILDLINK3_MK:=	${LIBSOUP24_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libsoup24
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibsoup24}
BUILDLINK_PACKAGES+=	libsoup24
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libsoup24

.if !empty(LIBSOUP24_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libsoup24+=	libsoup24>=2.4.0
BUILDLINK_ABI_DEPENDS.libsoup24?=	libsoup24>=2.4.0
BUILDLINK_PKGSRCDIR.libsoup24?=		../../net/libsoup24
.endif	# LIBSOUP24_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
