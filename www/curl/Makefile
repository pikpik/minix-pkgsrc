# $NetBSD: Makefile,v 1.3 2001/04/06 03:47:23 itojun Exp $

DISTNAME=	curl-7.7.1
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	client that groks URLs

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
