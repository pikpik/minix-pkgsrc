# $NetBSD$
#

DISTNAME=	libnet
PKGNAME=	libnet-1.0.1b
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.packetfactory.net/libnet/

DIST_SUBDIR=	${PKGNAME}

WRKSRC=		${WRKDIR}/Libnet-1.0.1b
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	LIBNET_CONFIG_LIBS="-L${PREFIX}/lib" \
		LIBNET_CONFIG_CFLAGS="-I${PREFIX}/include"

.include "../../mk/bsd.pkg.mk"
