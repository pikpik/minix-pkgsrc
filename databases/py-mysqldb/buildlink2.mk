# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:10 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pymysqldb
BUILDLINK_PKGBASE.pymysqldb?=	${PYPKGPREFIX}-mysqldb
BUILDLINK_DEPENDS.pymysqldb?=	${PYPKGPREFIX}-mysqldb-[0-9]*
BUILDLINK_PKGSRCDIR.pymysqldb?=	../../databases/py-mysqldb
