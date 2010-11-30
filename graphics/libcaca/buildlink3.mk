# $NetBSD$

BUILDLINK_DEPMETHOD.libcaca?=	build
BUILDLINK_TREE+=	libcaca

.if !defined(LIBCACA_BUILDLINK3_MK)
LIBCACA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcaca+=	libcaca>=0.9nb3
BUILDLINK_PKGSRCDIR.libcaca?=	../../graphics/libcaca
.endif	# LIBCACA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcaca
