# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:00 jlam Exp $

BUILDLINK_TREE+=	slatec

.if !defined(SLATEC_BUILDLINK3_MK)
SLATEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.slatec+=	slatec>=4.1nb1
BUILDLINK_ABI_DEPENDS.slatec+=	slatec>=4.1nb2
BUILDLINK_PKGSRCDIR.slatec?=	../../math/slatec
.endif # SLATEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-slatec
