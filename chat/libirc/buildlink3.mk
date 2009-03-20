# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:38 jlam Exp $

BUILDLINK_TREE+=	libirc

.if !defined(LIBIRC_BUILDLINK3_MK)
LIBIRC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libirc+=	libirc>=0.2nb1
BUILDLINK_ABI_DEPENDS.libirc+=	libirc>=0.2nb2
BUILDLINK_PKGSRCDIR.libirc?=	../../chat/libirc

.include "../../devel/glib/buildlink3.mk"
.endif # LIBIRC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libirc
