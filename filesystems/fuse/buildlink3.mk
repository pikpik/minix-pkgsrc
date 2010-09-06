# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:33 joerg Exp $

BUILDLINK_TREE+=	fuse

.if !defined(FUSEFS_BUILDLINK3_MK)
FUSEFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fuse+=	fuse>=2.5.2
BUILDLINK_PKGSRCDIR.fuse?=	../../filesystems/fuse

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
.include "../../filesystems/perfuse/buildlink3.mk"
.endif
.endif # FUSEFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-fuse
