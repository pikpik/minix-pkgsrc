# $NetBSD: Makefile,v 1.4 2001/08/27 14:35:07 tron Exp $

DISTNAME=	kmysqladmin-0.5.1
CATEGORIES=	databases kde
MASTER_SITES=	http://www.webeifer.de/alwin/programs/download/kmysqladmin/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=       http://www.webeifer.de/alwin/programs/kmysqladmin/
COMMENT=	MySQL administration GUI

AUTOMAKE_OVERRIDE=	YES
USE_BUILDLINK_ONLY=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-mysql-includes=${BUILDLINK_DIR}/include/mysql
CONFIGURE_ARGS+=	--with-mysql-libs=${BUILDLINK_DIR}/lib/mysql

.include "../../databases/mysql-client/buildlink.mk"
.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
