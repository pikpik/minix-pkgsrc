# $NetBSD: Makefile,v 1.4 2005/04/11 21:44:52 tv Exp $
#

DISTNAME=	faac-1.24
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=faac/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.audiocoding.com/
COMMENT=	AAC audio encoder

USE_LIBTOOL=	yes
USE_TOOLS+=	automake
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/faac

LIBTOOLIZE=	${PREFIX}/bin/libtoolize

pre-configure:
	cd ${WRKSRC};						\
	${LIBTOOLIZE} --automake;				\
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../mk/bsd.pkg.mk"
