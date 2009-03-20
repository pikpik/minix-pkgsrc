# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/04/25 23:09:44 wiz Exp $

BUILDLINK_TREE+=	libggz

.if !defined(LIBGGZ_BUILDLINK3_MK)
LIBGGZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libggz+=	libggz>=0.0.14.1
BUILDLINK_PKGSRCDIR.libggz?=	../../games/libggz

.include "../../security/gnutls/buildlink3.mk"
.endif # LIBGGZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-libggz
