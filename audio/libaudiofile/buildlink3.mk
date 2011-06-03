# $NetBSD: buildlink3.mk,v 1.14 2009/03/20 19:23:54 joerg Exp $

BUILDLINK_TREE+=	libaudiofile

.if !defined(AUDIOFILE_BUILDLINK3_MK)
AUDIOFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaudiofile+=	libaudiofile>=0.2.1
BUILDLINK_ABI_DEPENDS.libaudiofile+=	libaudiofile>=0.2.6nb1
BUILDLINK_PKGSRCDIR.libaudiofile?=	../../audio/libaudiofile
.endif # AUDIOFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaudiofile
