# $NetBSD: Makefile,v 1.13 2007/02/22 19:26:39 wiz Exp $

DISTNAME=	psyco-1.6-src
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-src//}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=psyco/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://psyco.sourceforge.net/
COMMENT=	Python JIT and execution accelerator

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
PYDISTUTILSPKG=	YES
PYBINMODULE=	YES
PY_PATCHPLIST=	YES

ONLY_FOR_PLATFORM=		*-*-i386

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
