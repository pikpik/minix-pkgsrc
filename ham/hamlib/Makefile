# $NetBSD: Makefile,v 1.6 2004/02/18 04:00:44 wulf Exp $
#

DISTNAME=	hamlib-1.2.0
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://hamlib.sourceforge/net/
COMMENT=	API for digital communications equipment

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
NO_EXPORT_CPP=	yes

.include "../../mk/bsd.pkg.mk"
