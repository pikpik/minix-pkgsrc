# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:08 jlam Exp $

.if !defined(PY_NUMERIC_BUILDLINK2_MK)
PY_NUMERIC_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pynumeric
BUILDLINK_DEPENDS.pynumeric?=	${PYPKGPREFIX}-Numeric-*
BUILDLINK_PKGSRCDIR.pynumeric?=	../../math/py-Numeric

EVAL_PREFIX+=   BUILDLINK_PREFIX.pynumeric=pynumeric
BUILDLINK_PREFIX.pynumeric_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pynumeric=	${PYINC}/Numeric/arrayobject.h
BUILDLINK_FILES.pynumeric+=	${PYINC}/Numeric/f2c.h
BUILDLINK_FILES.pynumeric+=	${PYINC}/Numeric/ranlib.h
BUILDLINK_FILES.pynumeric+=	${PYINC}/Numeric/ufuncobject.h

BUILDLINK_TARGETS+=	pynumeric-buildlink

pynumeric-buildlink: _BUILDLINK_USE

.endif	# PY_NUMERIC_BUILDLINK2_MK
