# $NetBSD: Makefile,v 1.3 2006/03/21 06:00:48 jlam Exp $
#

.include "../../print/evince/Makefile.common"

PKGNAME=		${DISTNAME:S/evince/evince-nautilus/}
PKGREVISION=		1

COMMENT=		File properties plugin for evince files

BUILD_DIRS=		libbackend lib properties
INSTALL_DIRS=		properties

.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
