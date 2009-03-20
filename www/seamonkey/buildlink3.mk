# $NetBSD: buildlink3.mk,v 1.8 2008/05/19 10:43:02 tnn Exp $

BUILDLINK_TREE+=	seamonkey

.if !defined(SEAMONKEY_BUILDLINK3_MK)
SEAMONKEY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.seamonkey+=	seamonkey>=1.0
BUILDLINK_ABI_DEPENDS.seamonkey?=	seamonkey>=1.0.1nb1
BUILDLINK_PKGSRCDIR.seamonkey?=		../../www/seamonkey

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # SEAMONKEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-seamonkey
