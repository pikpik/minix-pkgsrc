# $NetBSD: buildlink3.mk,v 1.9 2007/09/21 13:00:53 wiz Exp $

BUILDLINK_TREE+=	lablgtk

.if !defined(LABLGTK_BUILDLINK3_MK)
LABLGTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lablgtk+=	lablgtk>=2.6.0nb3
BUILDLINK_ABI_DEPENDS.lablgtk?=	lablgtk>=2.6.0nb5
BUILDLINK_PKGSRCDIR.lablgtk?=	../../x11/lablgtk
.endif # LABLGTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-lablgtk
