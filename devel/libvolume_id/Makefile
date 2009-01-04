# $NetBSD: Makefile,v 1.2 2008/11/26 07:47:56 hasso Exp $
#

DISTNAME=		libvolume_id-0.81.0
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.marcuscom.com/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Library to provide file system type information

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	include lib lib/pkgconfig 
USE_TOOLS+=		gmake pkg-config

USE_LIBTOOL=yes

.include "../../mk/bsd.pkg.mk"
