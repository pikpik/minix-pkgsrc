# $NetBSD: Makefile,v 1.9 2005/03/13 03:25:44 schmonz Exp $
#

DISTNAME=	checkpassword-0.90
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/checkpwd/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://cr.yp.to/checkpwd.html
COMMENT=	Simple, uniform password-checking interface to all root applications

DJB_RESTRICTED=		YES

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes

INSTALLATION_DIRS=	bin

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
