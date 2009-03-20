# $NetBSD: buildlink3.mk,v 1.9 2008/01/09 19:00:25 reed Exp $

BUILDLINK_TREE+=	Mowitz

.if !defined(MOWITZ_BUILDLINK3_MK)
MOWITZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Mowitz+=	Mowitz>=0.3.0
BUILDLINK_PKGSRCDIR.Mowitz?=	../../x11/mowitz

.include "../../x11/libXpm/buildlink3.mk"
.endif # MOWITZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-Mowitz
