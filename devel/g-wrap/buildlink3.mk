# $NetBSD: buildlink3.mk,v 1.11 2009/02/21 02:09:00 gdt Exp $

BUILDLINK_TREE+=	g-wrap

.if !defined(G_WRAP_BUILDLINK3_MK)
G_WRAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.g-wrap+=	g-wrap>=1.9.5
BUILDLINK_ABI_DEPENDS.g-wrap?=	g-wrap>=1.9.6nb1
BUILDLINK_PKGSRCDIR.g-wrap?=	../../devel/g-wrap

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.endif # G_WRAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-g-wrap
