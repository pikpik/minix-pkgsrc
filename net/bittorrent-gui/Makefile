# $NetBSD: Makefile,v 1.14 2004/03/02 15:49:36 wiz Exp $
#

.include "../../net/bittorrent/Makefile.common"

PKGNAME=	${DISTNAME:S/BitTorrent/bittorrent-gui/}

COMMENT+=	(wxGTK GUI)

DEPENDS+=	bittorrent-3.3nb5:../../net/bittorrent

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

PYTHON_PATCH_SCRIPTS= bin/btcompletedirgui.py bin/btdownloadgui.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/btcompletedirgui.py ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/btdownloadgui.py ${PREFIX}/bin

.include "../../x11/py-wxWindows/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
