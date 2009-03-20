# $NetBSD: buildlink3.mk,v 1.2 2008/02/08 11:53:06 tnn Exp $

BUILDLINK_TREE+=	fuse

.if !defined(FUSEFS_BUILDLINK3_MK)
FUSEFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fuse+=	fuse>=2.5.2
BUILDLINK_PKGSRCDIR.fuse?=	../../filesystems/fuse
.endif # FUSEFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-fuse
