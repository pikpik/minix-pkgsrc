# $NetBSD: buildlink3.mk,v 1.6 2004/03/05 19:25:06 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SDL_MIXER_BUILDLINK3_MK:=	${SDL_MIXER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	SDL_mixer
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NSDL_mixer}
BUILDLINK_PACKAGES+=	SDL_mixer

.if !empty(SDL_MIXER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.5nb2
BUILDLINK_PKGSRCDIR.SDL_mixer?=	../../audio/SDL_mixer
BUILDLINK_INCDIRS.SDL_mixer?=	include/SDL
.endif	# SDL_MIXER_BUILDLINK3_MK

.include "../../devel/SDL/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
