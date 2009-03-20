# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:35 jlam Exp $

BUILDLINK_TREE+=	cdplayer

.if !defined(CDPLAYER_BUILDLINK3_MK)
CDPLAYER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cdplayer+=	cdplayer>=0.4.2
BUILDLINK_ABI_DEPENDS.cdplayer?=	cdplayer>=0.4.2nb3
BUILDLINK_PKGSRCDIR.cdplayer?=	../../audio/cdplayer

.include "../../audio/libcdaudio/buildlink3.mk"
.include "../../audio/cddb-bundle/buildlink3.mk"
.endif # CDPLAYER_BUILDLINK3_MK

BUILDLINK_TREE+=	-cdplayer
