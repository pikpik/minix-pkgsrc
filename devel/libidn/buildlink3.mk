# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:11 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBIDN_BUILDLINK3_MK:=	${LIBIDN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libidn
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibidn}
BUILDLINK_PACKAGES+=	libidn

.if !empty(LIBIDN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libidn+=	libidn>=0.3.3
BUILDLINK_PKGSRCDIR.libidn?=	../../devel/libidn
.endif	# LIBIDN_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
