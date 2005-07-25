# $NetBSD: Makefile,v 1.24 2005/06/01 18:03:28 jlam Exp $

DISTNAME=	fox-1.4.16
CATEGORIES=	x11
MASTER_SITES=	http://www.fox-toolkit.org/ftp/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.fox-toolkit.org/
COMMENT=	Fast and extensive C++ GUI toolkit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-release
CONFIGURE_ARGS+=	--with-opengl
CONFIGURE_ARGS+=	--with-shm
CONFIGURE_ARGS+=	--with-x

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
