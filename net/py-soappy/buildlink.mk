# $NetBSD: buildlink.mk,v 1.1 2002/01/28 17:34:29 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pysoappy?= ${PYPKGPREFIX}-SOAPpy-*
DEPENDS+= ${BUILDLINK_DEPENDS.pysoappy}:../../net/py-soappy
