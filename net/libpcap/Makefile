# $NetBSD$
#

DISTNAME=	libpcap-0.4
CATEGORIES=	net
MASTER_SITES= 	ftp://ftp.ee.lbl.gov/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes

NOT_FOR_OPSYS=	NetBSD # in base system

INSTALL_TARGET+=	install-incl install-man

pre-install:
	-${MKDIR} ${LOCALBASE}/include/net

.include "../../mk/bsd.pkg.mk"
