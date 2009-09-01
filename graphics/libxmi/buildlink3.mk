# $NetBSD$

BUILDLINK_TREE+=	libxmi

.if !defined(LIBXMI_BUILDLINK3_MK)
LIBXMI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxmi+=	libxmi>=1.2
BUILDLINK_PKGSRCDIR.libxmi?=	../../graphics/libxmi
.endif	# LIBXMI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxmi
