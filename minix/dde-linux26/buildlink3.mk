# $NetBSD: buildlink3.mk,v 1.2 2009/01/28 05:38:53 obache Exp $

BUILDLINK_TREE+=	dde-linux26

.if !defined(DDE_LINUX26_LIB_BUILDLINK3_MK)
DDE_LINUX26_LIB_BUILDLINK3_MK:=

# The actual dependency recorded in the installed package
BUILDLINK_API_DEPENDS.dde-linux26+=	dde-linux26>=20
BUILDLINK_PKGSRCDIR.dde-linux26?=	../../minix/dde-linux26

.endif # DDE_LINUX26_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-dde-linux26
