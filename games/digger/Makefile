# $NetBSD$
#

DISTNAME=		digger-20020314
CATEGORIES=		games
MASTER_SITES=		http://www.digger.org/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.digger.org/
COMMENT=		Digger Remastered

USE_BUILDLINK2=		yes

MAKEFILE=		Makefile.fbsd
MAKE_FLAGS+=		-DSDL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/digger ${PREFIX}/bin/digger

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
