# $NetBSD: Makefile,v 1.10 2003/12/14 04:08:32 xtraeme Exp $
#

DISTNAME=	echoping-5.2.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://echoping.sourceforge.net/
COMMENT=	Test performance of a remote TCP service

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-icp
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-libidn=${BUILDLINK_PREFIX.libidn}

.include "../../devel/libidn/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
