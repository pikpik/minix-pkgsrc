# $NetBSD: buildlink3.mk,v 1.12 2007/03/27 06:32:06 tron Exp $

BUILDLINK_TREE+=	dlcompat

.if !defined(DLCOMPAT_BUILDLINK3_MK)
DLCOMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dlcompat+=	dlcompat>=20030629
BUILDLINK_PKGSRCDIR.dlcompat?=	../../devel/dlcompat
BUILDLINK_LDFLAGS.dlcompat+=	-ldl
.endif # DLCOMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-dlcompat
