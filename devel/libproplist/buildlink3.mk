# $NetBSD$
#
# This Makefile fragment is included by packages that use libproplist.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBPROPLIST_BUILDLINK3_MK:=	${LIBPROPLIST_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libproplist
.endif

.if !empty(LIBPROPLIST_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libproplist
BUILDLINK_DEPENDS.libproplist+=		libproplist>=0.10.1
BUILDLINK_PKGSRCDIR.libproplist?=		../../devel/libproplist

.endif # LIBPROPLIST_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
