# $NetBSD: Makefile,v 1.2 2004/11/22 15:45:18 adam Exp $

DISTNAME=	ctorrent-1.3.4
PKGREVISIN=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctorrent/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ctorrent.sourceforge.net/
COMMENT=	Bittorrent client for the console

USE_LANGUAGES=		c c++
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
