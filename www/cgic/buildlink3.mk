# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:11:12 jlam Exp $

BUILDLINK_TREE+=	cgic

.if !defined(CGIC_BUILDLINK3_MK)
CGIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cgic+=	cgic>=2.02nb1
BUILDLINK_PKGSRCDIR.cgic?=	../../www/cgic
.endif # CGIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-cgic
