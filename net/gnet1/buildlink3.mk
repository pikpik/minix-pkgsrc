# $NetBSD$
#
# This Makefile fragment is included by packages that use gnet1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNET1_BUILDLINK3_MK:=	${GNET1_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnet1
.endif

.if !empty(GNET1_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gnet1
BUILDLINK_DEPENDS.gnet1+=		gnet1>=1.1.8nb2
BUILDLINK_PKGSRCDIR.gnet1?=		../../net/gnet1

.include "../../devel/glib2/buildlink3.mk"

.endif # GNET1_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
