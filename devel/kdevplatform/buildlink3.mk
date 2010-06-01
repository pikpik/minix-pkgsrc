# $NetBSD$

BUILDLINK_TREE+=	kdevplatform

.if !defined(KDEVPLATFORM_BUILDLINK3_MK)
KDEVPLATFORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdevplatform+=	kdevplatform>=1.0.0
BUILDLINK_PKGSRCDIR.kdevplatform?=	../../devel/kdevplatform
.endif # KDEVPLATFORM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdevplatform
