# $NetBSD: Makefile,v 1.15 2001/08/24 11:23:16 abs Exp $
#

DISTNAME=	nmap-2.53
CATEGORIES=	net security
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.insecure.org/nmap/index.html
COMMENT=	Network/port scanner with OS detection

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	INSTALL=${INSTALL}
CONFIGURE_ARGS+=--with-libpcap=${BUILDLINK_DIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
MAKE_ENV+=	CPPFLAGS=""
.endif

.include "../../net/libpcap/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
