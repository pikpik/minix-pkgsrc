# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:11:11 jlam Exp $

BUILDLINK_TREE+=	libxml

.if !defined(LIBXML_BUILDLINK3_MK)
LIBXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxml+=	libxml>=1.8.11
BUILDLINK_ABI_DEPENDS.libxml+=	libxml>=1.8.17nb3
BUILDLINK_FILES.libxml+=	include/gnome-xml/libxml/*.h
BUILDLINK_PKGSRCDIR.libxml?=	../../textproc/libxml

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxml
