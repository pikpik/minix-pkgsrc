# $NetBSD: buildlink2.mk,v 1.3 2003/03/19 11:51:09 drochner Exp $

.if !defined(PYWXWINDOWS_BUILDLINK2_MK)
PYWXWINDOWS_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pywxWindows
BUILDLINK_DEPENDS.pywxWindows?=		${PYPKGPREFIX}-wxWindows-*
BUILDLINK_PKGSRCDIR.pywxWindows?=	../../x11/py-wxWindows

.endif	# PYWXWINDOWS_BUILDLINK2_MK
