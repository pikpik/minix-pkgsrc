# $NetBSD: Makefile,v 1.5 2000/07/20 15:40:58 tron Exp $
#

DISTNAME=	id3ed-1.10.2
CATEGORIES=	audio
MASTER_SITES=	http://www.azstarnet.com/~donut/programs/id3ed/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.azstarnet.com/~donut/programs/index.html

DEPENDS+=	readline>=4.0:../../devel/readline

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ENV+=	LIBS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"

post-extract:
	${TOUCH} ${WRKSRC}/install.sh

.include "../../mk/bsd.pkg.mk"
