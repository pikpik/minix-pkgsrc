# $NetBSD$
#
# This Makefile fragment is included by packages that use libtool.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBTOOL_BUILDLINK3_MK:=	${LIBTOOL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libtool
.endif

.if !empty(LIBTOOL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libtool
BUILDLINK_DEPENDS.libtool+=		libtool>=1.5.2
BUILDLINK_PKGSRCDIR.libtool?=		../../devel/libtool

.endif # LIBTOOL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
