# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:43 jlam Exp $

BUILDLINK_TREE+=	ldapsdk

.if !defined(LDAPSDK_BUILDLINK3_MK)
LDAPSDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ldapsdk+=	ldapsdk>=12311998
BUILDLINK_ABI_DEPENDS.ldapsdk?=	ldapsdk>=12311998nb2
BUILDLINK_PKGSRCDIR.ldapsdk?=	../../devel/ldapsdk
.endif # LDAPSDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-ldapsdk
