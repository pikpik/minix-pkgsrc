# $NetBSD$

BUILDLINK_TREE+=	libdbi

.if !defined(LIBDBI_BUILDLINK3_MK)
LIBDBI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbi+=	libdbi>=0.8.3
BUILDLINK_PKGSRCDIR.libdbi?=	../../databases/libdbi
.endif # LIBDBI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbi
