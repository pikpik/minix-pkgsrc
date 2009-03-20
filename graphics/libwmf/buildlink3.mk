# $NetBSD: buildlink3.mk,v 1.13 2006/07/08 23:10:52 jlam Exp $

BUILDLINK_TREE+=	libwmf

.if !defined(LIBWMF_BUILDLINK3_MK)
LIBWMF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwmf+=	libwmf>=0.2.8nb2
BUILDLINK_ABI_DEPENDS.libwmf+=	libwmf>=0.2.8.4nb3
BUILDLINK_PKGSRCDIR.libwmf?=	../../graphics/libwmf

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBWMF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwmf
