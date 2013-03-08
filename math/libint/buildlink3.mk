# $NetBSD$

# It only installs static library:
BUILDLINK_DEPMETHOD.libint?=	build

BUILDLINK_TREE+=	libint

.if !defined(LIBINT_BUILDLINK3_MK)
LIBINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libint+=	libint>=2.0.0
BUILDLINK_PKGSRCDIR.libint?=	../../math/libint
.endif	# LIBINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libint
