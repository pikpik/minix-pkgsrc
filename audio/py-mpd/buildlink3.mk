# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 17:30:09 joerg Exp $

BUILDLINK_TREE+=	py-mpd

.if !defined(PY_MPD_BUILDLINK3_MK)
PY_MPD_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-mpd+=	${PYPKGPREFIX}-mpd>=0.2.0
BUILDLINK_PKGSRCDIR.py-mpd?=	../../audio/py-mpd
.endif # PY_MPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-mpd
