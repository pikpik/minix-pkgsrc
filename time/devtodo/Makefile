# $NetBSD$
#

DISTNAME=	devtodo-0.1.3
CATEGORIES=	time
MASTER_SITES=	http://ftp1.sourceforge.net/devtodo/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/devtodo/
COMMENT=	Display and manage a list of items that are outstanding

GNU_CONFIGURE=	yes
MAKE_ENV+=	CXXFLAGS=-Wl,-R${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
