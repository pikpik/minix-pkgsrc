# $NetBSD: Makefile,v 1.10 1999/04/15 20:39:48 tron Exp $
#

DISTNAME=		dxpc-3.7.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://ccwf.cc.utexas.edu/~zvonler/dxpc/

GNU_CONFIGURE=		yes
USE_X11BASE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	egcs-1.1.2:../../lang/egcs
CONFIGURE_ENV+=	CXX=${LOCALBASE}/egcs/bin/g++
.endif

post-install:
	@strip ${PREFIX}/bin/dxpc

.include "../../mk/bsd.pkg.mk"
