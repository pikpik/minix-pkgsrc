# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/06/13 13:28:10 obache Exp $

BUILDLINK_TREE+=	libjudy

.if !defined(LIBJUDY_BUILDLINK3_MK)
LIBJUDY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libjudy+=	libjudy>=1.0.3
BUILDLINK_PKGSRCDIR.libjudy?=	../../devel/libjudy
.endif # LIBJUDY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libjudy
