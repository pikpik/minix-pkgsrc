# $NetBSD$

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_CURSES_BUILDLINK3_MK:=	${PY_CURSES_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pycurses
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npycurses}
BUILDLINK_PACKAGES+=	pycurses

.if !empty(PY_CURSES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pycurses+=	${PYPKGPREFIX}-curses-[0-9]*
BUILDLINK_PKGSRCDIR.pycurses?=	../../devel/py-curses
.endif	# PY_CURSES_BUILDLINK3_MK

.include "../../devel/ncurses/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
