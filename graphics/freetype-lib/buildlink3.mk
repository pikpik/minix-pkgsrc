# $NetBSD: buildlink3.mk,v 1.14 2006/07/08 23:10:51 jlam Exp $

BUILDLINK_TREE+=	freetype

.if !defined(FREETYPE_BUILDLINK3_MK)
FREETYPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freetype+=	freetype-lib>=1.3.1nb1
BUILDLINK_ABI_DEPENDS.freetype+=freetype-lib>=1.3.1nb2
BUILDLINK_ABI_DEPENDS.freetype?=	freetype-lib>=1.3.1nb3
BUILDLINK_PKGSRCDIR.freetype?=	../../graphics/freetype-lib

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # FREETYPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-freetype
