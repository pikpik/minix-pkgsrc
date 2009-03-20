# $NetBSD: buildlink3.mk,v 1.9 2009/02/03 06:11:12 obache Exp $

BUILDLINK_TREE+=	rplay

.if !defined(RPLAY_BUILDLINK3_MK)
RPLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rplay+=	rplay>=3.3.2nb1
BUILDLINK_ABI_DEPENDS.rplay+=	rplay>=3.3.2nb5
BUILDLINK_PKGSRCDIR.rplay?=	../../audio/rplay

.include "../../audio/gsm/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/rx/buildlink3.mk"
.endif # RPLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-rplay
