# $NetBSD: Makefile,v 1.4 2001/06/29 03:48:41 jlam Exp $

DISTNAME=	curl-7.8
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	client that groks URLs

USE_BUILDLINK_ONLY=	yes
REPLACE_BUILDLINK=	curl-config

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
