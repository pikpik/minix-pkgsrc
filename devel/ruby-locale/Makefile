# $NetBSD: Makefile,v 1.1.1.1 2009/12/07 10:47:50 fhajny Exp $

DISTNAME=	locale-2.0.5
CATEGORIES=	devel

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.yotabanana.com/hiki/ruby-locale.html
COMMENT=	Pure ruby library which provides basic APIs for localization
LICENSE=	ruby-license

pre-configure:
	${CHMOD} -R g-w ${WRKSRC}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
