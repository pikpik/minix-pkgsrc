# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/09/10 16:02:26 xtraeme Exp $

BUILDLINK_TREE+=	adplug

.if !defined(ADPLUG_BUILDLINK3_MK)
ADPLUG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adplug+=	adplug>=2.1
BUILDLINK_PKGSRCDIR.adplug?=	../../audio/adplug

.include "../../devel/libbinio/buildlink3.mk"
.endif # ADPLUG_BUILDLINK3_MK

BUILDLINK_TREE+=	-adplug
