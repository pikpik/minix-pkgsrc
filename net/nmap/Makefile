# $NetBSD: Makefile,v 1.16 2001/09/10 17:04:37 wiz Exp $
#

DISTNAME=	nmap-3.00
CATEGORIES=	net security
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.insecure.org/nmap/index.html
COMMENT=	Network/port scanner with OS detection

HAS_CONFIGURE=	YES
CONFIGURE_ENV+=	INSTALL=${INSTALL}
CONFIGURE_ENV+=	GTK_CONFIG=no
CONFIGURE_ARGS+=--with-libpcap=${BUILDLINK_DIR}
CONFIGURE_ARGS+=--prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
MAKE_ENV+=	CPPFLAGS=""
.endif

.include "../../net/libpcap/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
