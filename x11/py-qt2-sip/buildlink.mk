# $NetBSD: buildlink.mk,v 1.1 2002/01/28 17:34:29 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pyqt2sip?= ${PYPKGPREFIX}-qt2-sip-*
DEPENDS+= ${BUILDLINK_DEPENDS.pyqt2sip}:../../x11/py-qt2-sip
