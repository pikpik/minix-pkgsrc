# $NetBSD: Makefile,v 1.11 2004/10/03 00:18:10 tv Exp $

DISTNAME=	libnasl-${VERS}

.include	"../nessus/Makefile.common"

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=		${WRKDIR}/libnasl
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

.include "../../security/nessus-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
