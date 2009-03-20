# $NetBSD: buildlink3.mk,v 1.15 2009/02/27 22:50:43 wiz Exp $

BUILDLINK_TREE+=	libevent

.if !defined(LIBEVENT_BUILDLINK3_MK)
LIBEVENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libevent+=libevent>=0.6
BUILDLINK_ABI_DEPENDS.libevent+=libevent-1.4.9* # exact match -- see Makefile
BUILDLINK_PKGSRCDIR.libevent?=	../../devel/libevent
.endif # LIBEVENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libevent
