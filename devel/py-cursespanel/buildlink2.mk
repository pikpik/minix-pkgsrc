# $NetBSD: buildlink2.mk,v 1.3 2003/03/19 11:51:09 drochner Exp $

.if !defined(PYCURSESPANEL_BUILDLINK2_MK)
PYCURSESPANEL_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pycursespanel
BUILDLINK_DEPENDS.pycursespanel?=	${PYPKGPREFIX}-cursespanel-[0-9]*
BUILDLINK_PKGSRCDIR.pycursespanel?=	../../devel/py-cursespanel

.include "../../devel/py-curses/buildlink2.mk"

.endif	# PYCURSESPANEL_BUILDLINK2_MK
