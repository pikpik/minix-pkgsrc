# $NetBSD$
#

DISTNAME=	wtail-0.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.teaser.fr/~amajorel/wtail/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.teaser.fr/~amajorel/wtail/
COMMENT=	Watch multiple files at once

USE_BUILDLINK2=	YES

MAKE_ENV+=	SED="${SED}"

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
