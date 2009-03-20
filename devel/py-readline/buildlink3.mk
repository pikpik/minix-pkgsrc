# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:48 jlam Exp $

BUILDLINK_TREE+=	pyreadline

.if !defined(PYREADLINE_BUILDLINK3_MK)
PYREADLINE_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyreadline+=		${PYPKGPREFIX}-readline-[0-9]*
BUILDLINK_ABI_DEPENDS.pyreadline?=	${PYPKGPREFIX}-readline>=0nb2
BUILDLINK_PKGSRCDIR.pyreadline?=	../../devel/py-readline
.endif # PYREADLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyreadline
