# $NetBSD: Makefile,v 1.7 2004/03/26 02:27:55 wiz Exp $
#

.include "Makefile.common"

COMMENT=	GNUstep Workspace manager

pre-install:
	${CP} ${FILESDIR}/GNUmakefile ${WRKSRC}/GWLib

.include "../../sysutils/GWLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
