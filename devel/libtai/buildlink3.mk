# $NetBSD: buildlink3.mk,v 1.1 2008/07/30 10:36:27 schmonz Exp $

BUILDLINK_TREE+=	libtai

.if !defined(LIBTAI_BUILDLINK3_MK)
LIBTAI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtai+=	libtai>=0.60nb1
BUILDLINK_PKGSRCDIR.libtai?=	../../devel/libtai
BUILDLINK_DEPMETHOD.libtai?=	build
.endif # LIBTAI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtai
