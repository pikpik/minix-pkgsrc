# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:02 joerg Exp $

BUILDLINK_TREE+=	dirac

.if !defined(DIRAC_BUILDLINK3_MK)
DIRAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dirac+=	dirac>=1.0.2
BUILDLINK_PKGSRCDIR.dirac?=	../../multimedia/dirac
.endif # DIRAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-dirac
