# $NetBSD: buildlink.mk,v 1.1 2002/09/16 13:35:44 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pyreportlab?= ${PYPKGPREFIX}-reportlab-*
DEPENDS+= ${BUILDLINK_DEPENDS.pyreportlab}:../../print/py-reportlab
