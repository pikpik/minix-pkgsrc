# $NetBSD: Makefile,v 1.8 2006/05/22 20:21:59 wiz Exp $
#

DISTNAME=		tuxpaint-config-0.0.8
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.billsgames.com/unix/x/tuxpaint/config/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://ftp.billsgames.com/unix/x/tuxpaint/config/
COMMENT=		Configuration program for tuxpaint

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake

post-install:
	-${FIND} ${PREFIX}/share/tuxpaint-config -name CVS -exec ${RM} -r {} \; 2>/dev/null
	-${FIND} ${PREFIX}/share/tuxpaint-config -name .xvpics -exec ${RM} -r {} \; 2>/dev/null

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
