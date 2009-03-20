# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:04 jlam Exp $

BUILDLINK_TREE+=	pylibdnet

.if !defined(PYLIBDNET_BUILDLINK3_MK)
PYLIBDNET_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pylibdnet+=	${PYPKGPREFIX}-libdnet>=1.7
BUILDLINK_ABI_DEPENDS.pylibdnet?=	${PYPKGPREFIX}-libdnet>=1.10nb1
BUILDLINK_PKGSRCDIR.pylibdnet?=	../../net/py-libdnet
.endif # PYLIBDNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-pylibdnet
