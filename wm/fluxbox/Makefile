# $NetBSD: Makefile,v 1.5 2002/11/10 19:36:57 jmcneill Exp $
#

DISTNAME=	fluxbox-0.1.14
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fluxbox/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmcneill@netbsd.org
HOMEPAGE=	http://fluxbox.sourceforge.net/
COMMENT=	Window Manager for X based on Blackbox

DEPENDS+=	bsetroot>=0.1:../../wm/bsetroot

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_CXX=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-kde

.include "../../lang/gcc/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
