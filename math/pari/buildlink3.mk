# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:59 jlam Exp $

BUILDLINK_TREE+=	pari

.if !defined(PARI_BUILDLINK3_MK)
PARI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pari+=	pari>=2.1.5nb1
BUILDLINK_ABI_DEPENDS.pari+=	pari>=2.1.6nb1
BUILDLINK_PKGSRCDIR.pari?=	../../math/pari
.endif # PARI_BUILDLINK3_MK

BUILDLINK_TREE+=	-pari
