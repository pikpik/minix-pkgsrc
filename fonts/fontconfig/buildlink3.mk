# $NetBSD: buildlink3.mk,v 1.28 2012/05/07 01:53:29 dholland Exp $


BUILDLINK_TREE+=	fontconfig

FONTCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.4.2
BUILDLINK_ABI_DEPENDS.fontconfig+=	fontconfig>=2.8.0nb2
BUILDLINK_PKGSRCDIR.fontconfig?=	../../fonts/fontconfig

BUILDLINK_TREE+=	-fontconfig

