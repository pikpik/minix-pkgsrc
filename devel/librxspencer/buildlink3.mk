# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/02/21 21:06:12 minskim Exp $

BUILDLINK_TREE+=	librxspencer

.if !defined(LIBRXSPENCER_BUILDLINK3_MK)
LIBRXSPENCER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librxspencer+=	librxspencer>=3.8.3
BUILDLINK_PKGSRCDIR.librxspencer?=	../../devel/librxspencer
BUILDLINK_INCDIRS.librxspencer+=	include/rxspencer
.endif # LIBRXSPENCER_BUILDLINK3_MK

BUILDLINK_TREE+=	-librxspencer
