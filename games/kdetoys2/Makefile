# $NetBSD: Makefile,v 1.3 2001/10/15 22:46:18 skrll Exp $

DISTNAME=	kdetoys-2.2.1
CATEGORIES=	games
COMMENT=	Toys for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb1:../../x11/qt2-designer-kde

USE_BUILDLINK_ONLY=	YES

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
