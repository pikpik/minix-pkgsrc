# $NetBSD: Makefile,v 1.7 2009/12/16 19:30:31 joerg Exp $
#

DISTNAME=	embryo-1.1.0
CATEGORIES=	lang
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Embeddable Scripting Language

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	embryo.pc.in

.include "../../devel/eina/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
