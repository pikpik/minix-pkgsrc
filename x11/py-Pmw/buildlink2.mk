# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:56 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pypmw
BUILDLINK_PKGBASE.pypmw?=	${PYPKGPREFIX}-Pmw
BUILDLINK_DEPENDS.pypmw?=	${PYPKGPREFIX}-Pmw-[0-9]*
BUILDLINK_PKGSRCDIR.pypmw?=	../../x11/py-Pmw
