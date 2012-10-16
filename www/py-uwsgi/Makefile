# $NetBSD: Makefile,v 1.16 2012/07/12 16:21:53 roy Exp $

DISTNAME=	uwsgi-1.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://projects.unbit.it/downloads/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://projects.unbit.it/uwsgi
COMMENT=	Feature-rich WSGI server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c

PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
EGG_NAME=	${DISTNAME:S/uwsgi/uWSGI/}

post-install:
	mv ${DESTDIR}${PREFIX}/bin/uwsgi ${DESTDIR}${PREFIX}/bin/uwsgi-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
