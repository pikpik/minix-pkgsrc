# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:24 jlam Exp $

.if !defined(PY_MXDATETIME_BUILDLINK2_MK)
PY_MXDATETIME_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pymxdatetime
BUILDLINK_DEPENDS.pymxdatetime?=	${PYPKGPREFIX}-mxDateTime-[0-9]*
BUILDLINK_PKGSRCDIR.pymxdatetime?=	../../time/py-mxDateTime

.endif	# PY_MXDATETIME_BUILDLINK2_MK
