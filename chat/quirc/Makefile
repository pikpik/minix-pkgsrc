# $NetBSD: Makefile,v 1.4 2004/03/08 20:27:13 minskim Exp $
#

DISTNAME=	quirc-0.9.84
CATEGORIES=	chat
MASTER_SITES=	http://quirc.org/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://quirc.org/
COMMENT=	Stable and powerful graphical IRC client

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
