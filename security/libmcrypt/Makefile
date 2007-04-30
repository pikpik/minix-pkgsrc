# $NetBSD: Makefile,v 1.18 2006/03/04 21:30:34 jlam Exp $

DISTNAME=	libmcrypt-2.5.8
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcrypt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mcrypt.sourceforge.net/
COMMENT=	Crypto algorithms library

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

pre-install:
	mkdir ${PREFIX}/include/mutils

post-install:
	rmdir ${PREFIX}/lib/libmcrypt

.include "../../mk/bsd.pkg.mk"
