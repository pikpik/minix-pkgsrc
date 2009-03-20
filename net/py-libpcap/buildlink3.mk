# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:11:04 jlam Exp $

BUILDLINK_TREE+=	pylibpcap

.if !defined(PYLIBPCAP_BUILDLINK3_MK)
PYLIBPCAP_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pylibpcap+=	${PYPKGPREFIX}-libpcap>=0.5.0
BUILDLINK_ABI_DEPENDS.pylibpcap?=	${PYPKGPREFIX}-libpcap>=0.5nb1
BUILDLINK_PKGSRCDIR.pylibpcap?=	../../net/py-libpcap
.endif # PYLIBPCAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-pylibpcap
