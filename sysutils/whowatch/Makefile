# $NetBSD$
#

DISTNAME=	whowatch-1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/ \
		http://janek.ae.krakow.pl/~suszyckm/download/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://wizard.ae.krakow.pl/~mike/\#whowatch

DEPENDS+=	ncurses-*:../../devel/ncurses

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${PREFIX}/include"

.include "../../mk/bsd.pkg.mk"
