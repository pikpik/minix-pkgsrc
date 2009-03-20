# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/03/05 21:56:29 ahoka Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.5.7
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala

.include "../../devel/glib2/buildlink3.mk"
.endif # VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
