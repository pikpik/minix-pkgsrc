# $NetBSD: buildlink2.mk,v 1.2 2002/10/24 13:05:34 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pymetar
BUILDLINK_DEPENDS.pymetar?=	${PYPKGPREFIX}-pymetar-*
BUILDLINK_PKGSRCDIR.pymetar?=	../../net/py-METAR
