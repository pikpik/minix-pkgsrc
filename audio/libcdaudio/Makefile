# $NetBSD: Makefile,v 1.9 2001/11/29 01:12:25 hubertf Exp $
#

DISTNAME=		libcdaudio-0.99.6
CATEGORIES=		audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcdaudio/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://libcdaudio.sourceforge.net
COMMENT=		Multi-platform CD player development library

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
