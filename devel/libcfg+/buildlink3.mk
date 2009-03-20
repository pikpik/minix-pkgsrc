# $NetBSD: buildlink3.mk,v 1.7 2006/07/26 06:09:23 rillig Exp $

BUILDLINK_TREE+=	libcfg

.if !defined(LIBCFG_BUILDLINK3_MK)
LIBCFG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcfg+=	libcfg+>=0.6.2nb1
BUILDLINK_ABI_DEPENDS.libcfg+=	libcfg+>=0.6.2nb3
BUILDLINK_PKGSRCDIR.libcfg?=	../../devel/libcfg+
.endif # LIBCFG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcfg
