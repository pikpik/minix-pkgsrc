# $NetBSD: Makefile,v 1.9 2002/09/10 16:06:46 wiz Exp $

DISTNAME=	kdepim-2.2.2
PKGREVISION=	2
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK2=		YES
LTCONFIG_OVERRIDE+=	${WRKSRC}/libical/ltconfig

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
