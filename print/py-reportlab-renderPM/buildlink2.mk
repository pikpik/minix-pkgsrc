# $NetBSD: buildlink2.mk,v 1.1 2002/10/24 13:51:08 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyrlrenderpm
BUILDLINK_DEPENDS.pyrlrenderpm?= ${PYPKGPREFIX}-reportlab-renderPM-*
BUILDLINK_PKGSRCDIR.pyrlrenderpm=../../print/py-reportlab-renderPM
