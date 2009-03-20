# $NetBSD: buildlink3.mk,v 1.1 2008/01/09 03:53:10 smb Exp $

BUILDLINK_TREE+=	libytnef

.if !defined(LIBYTNEF_BUILDLINK3_MK)
LIBYTNEF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libytnef+=	libytnef>=1.5
BUILDLINK_PKGSRCDIR.libytnef?=	../../mail/libytnef
.endif # LIBYTNEF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libytnef
