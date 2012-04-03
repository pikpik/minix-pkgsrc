# $NetBSD: buildlink3.mk,v 1.18 2012/03/03 00:12:34 wiz Exp $

BUILDLINK_TREE+=	libkexiv2

.if !defined(LIBKEXIV2_BUILDLINK3_MK)
LIBKEXIV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkexiv2+=	libkexiv2>=4.8.0
BUILDLINK_PKGSRCDIR.libkexiv2?=	../../graphics/libkexiv2

.endif	# LIBKEXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkexiv2
