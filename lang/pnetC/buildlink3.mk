# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:10:55 jlam Exp $

BUILDLINK_TREE+=	pnetC

.if !defined(PNETC_BUILDLINK3_MK)
PNETC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pnetC+=	pnetC>=0.6.4
BUILDLINK_ABI_DEPENDS.pnetC?=	pnetC>=0.6.6nb2
BUILDLINK_PKGSRCDIR.pnetC?=	../../lang/pnetC

.include "../../lang/pnet/buildlink3.mk"
.endif # PNETC_BUILDLINK3_MK

BUILDLINK_TREE+=	-pnetC
