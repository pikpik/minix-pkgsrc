# $NetBSD: buildlink.mk,v 1.1 2002/09/16 13:35:44 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyxml
BUILDLINK_DEPENDS.pyxml?=	${PYPKGPREFIX}-xml-*
BUILDLINK_PKGSRCDIR.pyxml?=	../../textproc/pyxml
