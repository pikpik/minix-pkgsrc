# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:48 jlam Exp $

BUILDLINK_TREE+=	syncdir

.if !defined(SYNCDIR_BUILDLINK3_MK)
SYNCDIR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.syncdir+=	syncdir>=1.0
BUILDLINK_ABI_DEPENDS.syncdir+=	syncdir>=1.0nb1
BUILDLINK_PKGSRCDIR.syncdir?=	../../devel/syncdir
.endif # SYNCDIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-syncdir
