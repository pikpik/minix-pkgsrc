# $NetBSD: Makefile,v 1.12 2003/03/28 21:14:39 wiz Exp $
#

COMMENT=	Open new window using netscape like browser

BINNAME=	netscape

.include "../navigator/Makefile.common"

NETSCAPE_PREFERRED_DEFAULT=netscape7:communicator:navigator:phoenix-bin:phoenix:mozilla
.if defined(NS_PREFERRED)
NETSCAPE_PREFERRED=${NS_PREFERRED}:${NETSCAPE_PREFERRED_DEFAULT}
.else
NETSCAPE_PREFERRED=${NETSCAPE_PREFERRED_DEFAULT}
.endif

DEPENDS+= ns-remote>=1.3:../../www/ns-remote
DEPENDS+={${NETSCAPE_PREFERRED:C/:/,/g}}-[0-9]*:../../www/${NETSCAPE_PREFERRED:C/:.*//}

DISTFILES=	# empty
MASTER_SITES=	# empty

USE_BUILDLINK2=	# defined

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

do-build:
	${SED} "s/@NETSCAPE_PREFERRED@/${NETSCAPE_PREFERRED}/" \
				${FILESDIR}/netscape > ${WRKSRC}/netscape

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${PREFIX}/bin/netscape

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
