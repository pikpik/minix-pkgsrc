# $NetBSD: buildlink.mk,v 1.1 2002/01/28 17:34:29 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pypmw?= ${PYPKGPREFIX}-Pmw-*
DEPENDS+= ${BUILDLINK_DEPENDS.pypmw}:../../x11/py-Pmw
