# $NetBSD: buildlink3.mk,v 1.4 2012/03/03 00:12:21 wiz Exp $
#

BUILDLINK_TREE+=	ibus

.if !defined(IBUS_BUILDLINK3_MK)
IBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ibus+=	ibus>=1.4.0
BUILDLINK_PKGSRCDIR.ibus?=	../../inputmethod/ibus

.include "../../devel/glib2/buildlink3.mk"
.endif	# IBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ibus
