# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/08/13 05:29:27 dan Exp $

BUILDLINK_TREE+=	meanwhile

.if !defined(MEANWHILE_BUILDLINK3_MK)
MEANWHILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.meanwhile+=	meanwhile>=1.0.2
BUILDLINK_PKGSRCDIR.meanwhile?=	../../chat/meanwhile
.endif # MEANWHILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-meanwhile
