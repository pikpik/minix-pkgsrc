# $NetBSD: Makefile,v 1.1.1.1 2000/12/08 16:47:50 wiz Exp $
#

DISTNAME=	echoping-4.1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://echoping.sourceforge.net/

GNU_CONFIGURE=	YES
USE_SSL=	YES
CONFIGURE_ARGS+=--enable-icp
CONFIGURE_ARGS+=--with-ssl=${SSLBASE}

.include "../../mk/bsd.pkg.mk"
