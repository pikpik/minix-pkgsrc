# $NetBSD: Makefile,v 1.1.1.1 2001/03/10 20:00:43 hubertf Exp $
#

.include "../bbkeys/Makefile.common"

PKGNAME=	bbkeys-qt-1.2
COMMENT=	Qt-based configuration utility for bbkeys

DEPENDS+=	bbkeys-0.3.5:../bbkeys

WRKSRC=		${WRKDIR}/bbkeys-0.3.5/bbkeysconf-1.2

.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
