# $NetBSD: Makefile,v 1.5 2004/03/26 02:27:38 wiz Exp $
#
.include "../../x11/gtoolkit/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-examples-/}
PKGREVISION=	4
CATEGORIES=	devel

COMMENT=	Objective-C examples for GToolKit

DISTINFO_FILE=	${.CURDIR}/../../x11/gtoolkit/distinfo
BUILD_DIRS=	${WRKSRC}/Examples

.include "../../x11/gtoolkit/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
