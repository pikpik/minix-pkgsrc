# $NetBSD$

BUILDLINK_TREE+=	libifp

.if !defined(LIBIFP_BUILDLINK3_MK)
LIBIFP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libifp+=	libifp>=1.0.0.2
BUILDLINK_PKGSRCDIR.libifp?=	../../nih/libifp

.include "../../devel/libusb/buildlink3.mk"
.endif	# LIBIFP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libifp
