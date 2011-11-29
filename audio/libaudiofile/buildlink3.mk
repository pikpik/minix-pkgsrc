# $NetBSD: buildlink3.mk,v 1.15 2011/04/21 21:06:25 hans Exp $

BUILDLINK_TREE+=	libaudiofile

.if !defined(LIBAUDIOFILE_BUILDLINK3_MK)
LIBAUDIOFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaudiofile+=	libaudiofile>=0.2.1
BUILDLINK_ABI_DEPENDS.libaudiofile+=	libaudiofile>=0.2.6nb1
BUILDLINK_PKGSRCDIR.libaudiofile?=	../../audio/libaudiofile
.endif # LIBAUDIOFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaudiofile
