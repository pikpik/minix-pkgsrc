# $NetBSD: buildlink3.mk,v 1.10 2007/11/11 21:53:57 rillig Exp $

BUILDLINK_TREE+=	libotr

.if !defined(LIBOTR_BUILDLINK3_MK)
LIBOTR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libotr+=	libotr>=3.0.0
BUILDLINK_PKGSRCDIR.libotr?=	../../chat/libotr

.include "../../security/libgcrypt/buildlink3.mk"
.endif # LIBOTR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libotr
