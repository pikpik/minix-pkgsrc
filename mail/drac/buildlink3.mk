# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:57 jlam Exp $

BUILDLINK_TREE+=	drac

.if !defined(DRAC_BUILDLINK3_MK)
DRAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.drac+=	drac>=1.10
BUILDLINK_PKGSRCDIR.drac?=	../../mail/drac
BUILDLINK_DEPMETHOD.drac?=	build
.endif # DRAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-drac
