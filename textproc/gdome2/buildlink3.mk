# $NetBSD: buildlink3.mk,v 1.12 2012/05/07 01:54:02 dholland Exp $

BUILDLINK_TREE+=	gdome2

.if !defined(GDOME2_BUILDLINK3_MK)
GDOME2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdome2+=	gdome2>=0.8.1nb1
BUILDLINK_ABI_DEPENDS.gdome2+=	gdome2>=0.8.1nb6
BUILDLINK_PKGSRCDIR.gdome2?=	../../textproc/gdome2

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # GDOME2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdome2
