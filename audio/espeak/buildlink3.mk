# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/07/17 19:18:44 drochner Exp $

BUILDLINK_TREE+=	espeak

.if !defined(ESPEAK_BUILDLINK3_MK)
ESPEAK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.espeak+=	espeak>=1.26
BUILDLINK_PKGSRCDIR.espeak?=	../../audio/espeak

.include "../../audio/portaudio/buildlink3.mk"
.endif # ESPEAK_BUILDLINK3_MK

BUILDLINK_TREE+=	-espeak
