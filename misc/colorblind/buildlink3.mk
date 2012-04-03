# $NetBSD$
#

BUILDLINK_TREE+=	colorblind

.if !defined(COLORBLIND_BUILDLINK3_MK)
COLORBLIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.colorblind+=	colorblind>=0.0.1
BUILDLINK_PKGSRCDIR.colorblind?=	../../misc/colorblind
.endif	# COLORBLIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-colorblind
