# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 18:23:21 jwise Exp $

DISTNAME=	modxslt
PKGNAME=	ap-xslt-1.1
CATEGORIES=	www
MASTER_SITES=	http://modxslt.userworld.com/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://modxslt.userworld.com/
COMMENT=	Simple, fast XSLT transformations for apache

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
DEPENDS+=	sablotron-*:../../textproc/sablotron

# For "apxs":
BUILD_DEPENDS+= perl>=${PERL5_REQD}:../../lang/perl5

do-install:
		${LOCALBASE}/sbin/apxs -i ${WRKSRC}/mod_xslt.so

.include "../../mk/bsd.pkg.mk"
