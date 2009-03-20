# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/01/12 14:09:35 dillo Exp $

BUILDLINK_TREE+=	libsyncml

.if !defined(LIBSYNCML_BUILDLINK3_MK)
LIBSYNCML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsyncml+=	libsyncml>=0.4.5
BUILDLINK_PKGSRCDIR.libsyncml?=	../../comms/libsyncml
.endif # LIBSYNCML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsyncml
