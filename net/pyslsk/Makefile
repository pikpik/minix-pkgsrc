# $NetBSD: Makefile,v 1.3 2003/07/17 22:51:44 grant Exp $
#

DISTNAME=	pyslsk-1.2.4
CATEGORIES=	net audio x11
MASTER_SITES=	http://www.sensi.org/~ak/pyslsk/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.sensi.org/~ak/pyslsk/
COMMENT=	Python based Soulseek client

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED= 23pth 22pth

.include "../../x11/py-wxWindows/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
