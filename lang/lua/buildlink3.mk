# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:10:55 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LUA_BUILDLINK3_MK:=	${LUA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	lua
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlua}
BUILDLINK_PACKAGES+=	lua
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}lua

.if !empty(LUA_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.lua+=	lua>=5.1.1
BUILDLINK_PKGSRCDIR.lua?=	../../lang/lua
.endif	# LUA_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
