# $NetBSD: buildlink2.mk,v 1.3 2003/03/19 11:51:09 drochner Exp $

.if !defined(PYCURSES_BUILDLINK2_MK)
PYCURSES_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pycurses
BUILDLINK_DEPENDS.pycurses?=		${PYPKGPREFIX}-curses-[0-9]*
BUILDLINK_PKGSRCDIR.pycurses?=		../../devel/py-curses

.endif	# PYCURSES_BUILDLINK2_MK
