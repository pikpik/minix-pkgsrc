# $NetBSD: Makefile,v 1.5 2009/01/26 23:38:13 explorer Exp $

DISTNAME=	ldns-1.5.1
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/drill/
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/ldns/

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/projects/ldns/
COMMENT=	Library for simplified DNS programming
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-sha2

REPLACE_PERL=	doc/doxyparse.pl

BUILDLINK_ABI_DEPENDS.openssl+= openssl>=0.9.7

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
