# $NetBSD$
#

DISTNAME=       rcs-5.7
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=/rcs/}

MAINTAINER=	gnu@gnu.org
HOMEPAGE=	http://www.gnu.org/software/rcs/rcs.html

NOT_FOR_OPSYS=	NetBSD # in the base system

DEPENDS+=	diffutils-2.7:../../devel/diffutils

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PATH=${LOCALBASE}/bin:$PATH

.include "../../mk/bsd.pkg.mk"
