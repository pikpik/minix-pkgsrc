# $NetBSD: Makefile,v 1.20 2012/10/03 11:24:42 asau Exp $
#

DISTNAME=	openobex-1.7-Source
PKGNAME=	openobex-1.7
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitorious.org/openobex
COMMENT=	Implementation of the Object Exchange (OBEX) protocol
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	cmake pkg-config

PKGCONFIG_OVERRIDE=	openobex.pc.in

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
