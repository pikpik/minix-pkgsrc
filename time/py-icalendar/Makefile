# $NetBSD: Makefile,v 1.4 2012/01/20 12:08:47 wiz Exp $
#

DISTNAME=	icalendar-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	http://pypi.python.org/packages/source/i/icalendar/

MAINTAINER=	mj@turner.org.za
HOMEPAGE=	http://codespeak.net/icalendar/
COMMENT=	Python parser/generator for iCalendar files, as per RFC2445
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
