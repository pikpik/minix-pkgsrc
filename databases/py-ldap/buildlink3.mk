# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:07 joerg Exp $

BUILDLINK_TREE+=	py-ldap

.if !defined(PY_LDAP_BUILDLINK3_MK)
PY_LDAP_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-ldap+=	${PYPKGPREFIX}-ldap>=2.2.0
BUILDLINK_ABI_DEPENDS.py-ldap+=	${PYPKGPREFIX}-ldap>=2.2.0
BUILDLINK_PKGSRCDIR.py-ldap?=	../../databases/py-ldap
.endif # PY_LDAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-ldap
