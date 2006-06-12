# $NetBSD: buildlink3.mk,v 1.7 2006/04/12 10:27:29 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SDL_NET_BUILDLINK3_MK:=	${SDL_NET_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	SDL_net
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NSDL_net}
BUILDLINK_PACKAGES+=	SDL_net

.if !empty(SDL_NET_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.SDL_net+=	SDL_net>=1.2.5nb1
BUILDLINK_ABI_DEPENDS.SDL_net+=	SDL_net>=1.2.6
BUILDLINK_PKGSRCDIR.SDL_net?=	../../net/SDL_net
.endif	# SDL_NET_BUILDLINK3_MK

.include "../../devel/SDL/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
