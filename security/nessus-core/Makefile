# $NetBSD: Makefile,v 1.2 2001/02/17 17:49:54 wiz Exp $
#

DISTNAME=	nessus-core-${VERS}
.include 	"../nessus/Makefile.common"

COMMENT=	Core module of the Nessus Network Security Scanner

WRKSRC=		${WRKDIR}/nessus-core

USE_BUILDLINK2=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-gtk \
		--with-x \
		--localstatedir=/var

.include "../../security/libnasl/buildlink2.mk"
.include "../../security/nessus-libraries/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
