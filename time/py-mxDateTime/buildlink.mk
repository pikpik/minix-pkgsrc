# $NetBSD$

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pymxdatetime?= ${PYPKGPREFIX}-mxDateTime-*
DEPENDS+= ${BUILDLINK_DEPENDS.pymxdatetime}:../../time/py-mxDateTime
