# $NetBSD: Makefile,v 1.8 2002/01/22 22:21:41 wiz Exp $

DISTNAME=	modxslt
PKGNAME=	ap-xslt-1.1
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://download.sourceforge.net/modxslt/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://modxslt.sourceforge.net/
COMMENT=	Simple, fast XSLT transformations for apache

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
DEPENDS+=	sablotron-*:../../textproc/sablotron

USE_PERL5=	build	# for "apxs"

do-install:
		${LOCALBASE}/sbin/apxs -i ${WRKSRC}/mod_xslt.so

.include "../../mk/bsd.pkg.mk"
