# $NetBSD$
#

DISTNAME=	nessus-plugins-${VERS}
.include	"../nessus/Makefile.common"

DEPENDS+=	nessus-core-${VERS}:../nessus-core
DEPENDS+=	nmap-2.*:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
