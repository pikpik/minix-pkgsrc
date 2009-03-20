# $NetBSD: buildlink3.mk,v 1.13 2006/07/08 23:10:36 jlam Exp $

BUILDLINK_TREE+=	audiofile

.if !defined(AUDIOFILE_BUILDLINK3_MK)
AUDIOFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.audiofile+=	libaudiofile>=0.2.1
BUILDLINK_ABI_DEPENDS.audiofile+=	libaudiofile>=0.2.6nb1
BUILDLINK_PKGSRCDIR.audiofile?=	../../audio/libaudiofile
.endif # AUDIOFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-audiofile
