# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:07 tv Exp $

DISTNAME=	libopendaap-0.3.0
CATEGORIES=	audio
MASTER_SITES=	http://crazney.net/programs/itunes/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://crazney.net/programs/itunes/libopendaap.html
COMMENT=	DAAP client library

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/pkgconfig/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
