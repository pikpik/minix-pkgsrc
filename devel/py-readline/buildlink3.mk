# $NetBSD: buildlink3.mk,v 1.20 2004/11/15 14:56:36 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PYREADLINE_BUILDLINK3_MK:=	${PYREADLINE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyreadline
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyreadline}
BUILDLINK_PACKAGES+=	pyreadline

.if !empty(PYREADLINE_BUILDLINK3_MK:M+)

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pyreadline+=		${PYPKGPREFIX}-readline-[0-9]*
BUILDLINK_PKGSRCDIR.pyreadline?=	../../devel/py-readline

.endif	# PYREADLINE_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
