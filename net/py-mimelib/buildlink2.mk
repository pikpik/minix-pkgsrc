# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/12/03 19:34:59 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pymimelib
BUILDLINK_DEPENDS.pymimelib?=	${PYPKGPREFIX}-mimelib-[0-9]*
BUILDLINK_PKGSRCDIR.pymimelib?=	../../net/py-mimelib
