# $NetBSD: Makefile,v 1.3 2000/05/24 14:52:49 mrg Exp $
#

DISTNAME=	bozohttpd-5.05
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
		
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && (${USE_INET6} == "YES")
CPPFLAGS+=	-DINET6
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"
.endif

.include "../../mk/bsd.pkg.mk"
