# $NetBSD: Makefile,v 1.6 2005/03/13 03:25:44 schmonz Exp $
#

DISTNAME=	service-config-0.51
CATEGORIES=	sysutils
MASTER_SITES=	http://www.superscript.com/service-config/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.superscript.com/service-config/intro.html
COMMENT=	Utility to create and configure svscan service directories

DEPENDS+=	daemontools-[0-9]*:../../sysutils/daemontools

BUILD_TARGET=	it
INSTALL_TARGET=	setup check

# Possibly inherited DJB-style distribution terms
DJB_RESTRICTED=	YES

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
