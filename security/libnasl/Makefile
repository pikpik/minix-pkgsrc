# $NetBSD$
#

DISTNAME=	libnasl-${VERS}
.include	"../nessus/Makefile.common"

DEPENDS+=       nessus-libraries-${VERS}:../nessus-libraries

WRKSRC=		${WRKDIR}/libnasl

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP=${CPP}

.include "../../mk/bsd.pkg.mk"
