# $NetBSD: Makefile,v 1.8 2004/01/22 07:49:21 grant Exp $
#

DISTNAME=	ser-0.8.10_src
PKGNAME=	ser-0.8.10
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.berlios.de/pub/ser/latest/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.iptel.org/ser/
COMMENT=	SIP express router

WRKSRC=		${WRKDIR}/ser-0.8.10

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

MAKE_ENV+= BUILDLINK_PREFIX.pthread=${BUILDLINK_PREFIX.pthread:Q}
MAKE_ENV+= BUILDLINK_PREFIX.mysql-client=${BUILDLINK_PREFIX.mysql-client:Q}
MAKE_ENV+= BUILDLINK_PREFIX.expat=${BUILDLINK_PREFIX.expat:Q}

.include "../../databases/mysql-client/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
