# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:58 jlam Exp $

.if !defined(PY_GTK_BUILDLINK2_MK)

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pygtk
BUILDLINK_DEPENDS.pygtk?=	${PYPKGPREFIX}-gtk-[0-9]*
BUILDLINK_PKGSRCDIR.pygtk?=	../../x11/pygtk

.endif	# PY_GTK_BUILDLINK2_MK
