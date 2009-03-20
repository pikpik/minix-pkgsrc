# $NetBSD: buildlink3.mk,v 1.3 2009/03/18 11:58:08 jmcneill Exp $

BUILDLINK_TREE+=	opal

.if !defined(OPAL_BUILDLINK3_MK)
OPAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opal+=	opal>=3.6.1
BUILDLINK_ABI_DEPENDS.opal?=	opal>=3.6.1
BUILDLINK_PKGSRCDIR.opal?=	../../devel/opal

.include "../../devel/ptlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # OPAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-opal
