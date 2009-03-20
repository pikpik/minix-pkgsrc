# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/08/19 17:51:14 bjs Exp $

BUILDLINK_TREE+=	babl

.if !defined(BABL_BUILDLINK3_MK)
BABL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.babl+=	babl>=0.0.22
BUILDLINK_PKGSRCDIR.babl?=	../../graphics/babl

.include "../../mk/dlopen.buildlink3.mk"
.endif # BABL_BUILDLINK3_MK

BUILDLINK_TREE+=	-babl
