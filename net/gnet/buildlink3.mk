# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:11:03 jlam Exp $

BUILDLINK_TREE+=	gnet

.if !defined(GNET_BUILDLINK3_MK)
GNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnet+=	gnet>=2.0.3nb1
BUILDLINK_ABI_DEPENDS.gnet+=	gnet>=2.0.7nb2
BUILDLINK_PKGSRCDIR.gnet?=	../../net/gnet

.include "../../devel/glib2/buildlink3.mk"
.endif # GNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnet
