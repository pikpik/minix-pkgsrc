# $NetBSD: Makefile,v 1.6 2010/01/12 01:34:18 obache Exp $
#

DISTNAME=	urlgrabber-3.1.0
PKGREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	http://urlgrabber.baseurl.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://urlgrabber.baseurl.org/
COMMENT=	Python package that drastically simplifies the fetching of files

PKG_DESTDIR_SUPPORT=		user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=			yes
PY_PATCHPLIST=			yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
