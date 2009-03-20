# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/10/24 16:37:49 wiz Exp $

BUILDLINK_TREE+=	gmime24

.if !defined(GMIME24_BUILDLINK3_MK)
GMIME24_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmime24+=	gmime24>=2.4.3
BUILDLINK_PKGSRCDIR.gmime24?=	../../mail/gmime24

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # GMIME24_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmime24
