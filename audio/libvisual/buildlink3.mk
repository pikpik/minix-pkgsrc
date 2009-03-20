# $NetBSD: buildlink3.mk,v 1.10 2007/12/29 16:11:38 joerg Exp $

BUILDLINK_TREE+=	libvisual

.if !defined(LIBVISUAL_BUILDLINK3_MK)
LIBVISUAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvisual+=	libvisual>=0.4.0
BUILDLINK_PKGSRCDIR.libvisual?=		../../audio/libvisual

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # LIBVISUAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvisual
