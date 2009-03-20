# $NetBSD: buildlink3.mk,v 1.7 2009/03/19 17:05:51 cube Exp $

BUILDLINK_DEPMETHOD.clearsilver?=	build

BUILDLINK_TREE+=	clearsilver-base

.if !defined(CLEARSILVER_BUILDLINK3_MK)
CLEARSILVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clearsilver+=		clearsilver-base>=0.9.0
BUILDLINK_ABI_DEPENDS.clearsilver+=	clearsilver>=0.10.1
BUILDLINK_PKGSRCDIR.clearsilver?=	../../www/clearsilver-base
.endif # CLEARSILVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-clearsilver-base
