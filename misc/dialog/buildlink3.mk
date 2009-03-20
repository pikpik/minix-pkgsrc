# $NetBSD: buildlink3.mk,v 1.1 2008/10/08 09:34:00 wiz Exp $

BUILDLINK_TREE+=	dialog

.if !defined(DIALOG_BUILDLINK3_MK)
DIALOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dialog+=	dialog>=1.1.20080819nb1
BUILDLINK_PKGSRCDIR.dialog?=	../../misc/dialog

.include "../../devel/ncurses/buildlink3.mk"
.endif # DIALOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-dialog
