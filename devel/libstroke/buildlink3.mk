# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:10:46 jlam Exp $

BUILDLINK_TREE+=	libstroke

.if !defined(LIBSTROKE_BUILDLINK3_MK)
LIBSTROKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstroke+=	libstroke>=0.5.1
BUILDLINK_ABI_DEPENDS.libstroke+=	libstroke>=0.5.1nb2
BUILDLINK_PKGSRCDIR.libstroke?=	../../devel/libstroke

.include "../../lang/tcl/buildlink3.mk"
.endif # LIBSTROKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstroke
