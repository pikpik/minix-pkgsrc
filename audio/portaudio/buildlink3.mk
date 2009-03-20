# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:37 jlam Exp $

BUILDLINK_TREE+=	portaudio

.if !defined(PORTAUDIO_BUILDLINK3_MK)
PORTAUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.portaudio+=	portaudio>=18.1
BUILDLINK_ABI_DEPENDS.portaudio?=	portaudio>=18.1nb2
BUILDLINK_PKGSRCDIR.portaudio?=	../../audio/portaudio
.endif # PORTAUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-portaudio
