# $NetBSD: Makefile,v 1.1.1.1 1999/06/05 23:54:51 hubertf Exp $
#

DISTNAME=	id3ed-1.7
CATEGORIES=	audio
MASTER_SITES=	http://www.azstarnet.com/~donut/id3ed/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.azstarnet.com/~donut/programs.html

DEPENDS+=	readline-2.2:../../devel/readline

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ENV+=	LIBS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"

post-extract:
	${TOUCH} ${WRKSRC}/install.sh

.include "../../mk/bsd.pkg.mk"
