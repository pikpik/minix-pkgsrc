# $NetBSD: Makefile,v 1.8 2003/07/21 16:51:52 martti Exp $
#

DISTNAME=	tuxpaint-stamps-2003.12.23
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.newbreedsoftware.com/tuxpaint/
COMMENT=	Rubber stamps for Tux Paint

DEPENDS+=	tuxpaint>=0.9.13:../../graphics/tuxpaint

CONFLICTS+=	tuxpaint<0.9.13

post-install:
	-${FIND} ${PREFIX}/share/tuxpaint/stamps -name CVS -exec \
		 ${RM} -r {} \; 2>/dev/null

.include "../../mk/bsd.pkg.mk"
