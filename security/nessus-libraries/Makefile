# $NetBSD: Makefile,v 1.4 2001/09/27 23:18:39 jlam Exp $
#

DISTNAME=	nessus-libraries-${VERS}
.include 	"../nessus/Makefile.common"

COMMENT=	Libs required by the Nessus Network security scanner

USE_LIBTOOL=	yes
USE_SSL=	yes

DEPENDS+=	bison-*:../../devel/bison

WRKSRC=		${WRKDIR}/nessus-libraries

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP=${CPP}
CONFIGURE_ARGS+=--enable-zlib=/usr/lib

.include "../../mk/bsd.pkg.mk"
