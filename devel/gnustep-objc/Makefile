# $NetBSD: Makefile,v 1.5 2003/07/17 21:30:54 grant Exp $
#

DISTNAME=	gnustep-objc-1.3.0
CATEGORIES=	devel gnustep
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/libs/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Objective-C runtime

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
MAKEFILE=		GNUmakefile
NO_CONFIGURE=		YES

.include "../../devel/gnustep-make/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
