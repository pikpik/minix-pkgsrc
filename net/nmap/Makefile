# $NetBSD: Makefile,v 1.18 2002/10/10 13:28:29 wiz Exp $
#

DISTNAME=	nmap-3.20
CATEGORIES=	net security
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.insecure.org/nmap/index.html
COMMENT=	Network/port scanner with OS detection

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--without-nmapfe

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
MAKE_ENV+=	CPPFLAGS=""
.endif

.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
