# $NetBSD: Makefile,v 1.4 1999/08/25 13:37:36 agc Exp $
#

DISTNAME=	emiclock-2.0.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.noge.com/pub/EmiClock/X11/

MAINTAINER=	minoura@netbsd.org

USE_X11BASE=	yes
USE_IMAKE=	yes
USE_XAW=	yes

.include "../../mk/bsd.prefs.mk"

XAW_TYPE?=	3d

post-install:
	$(MKDIR) $(PREFIX)/lib/X11/ja_JP.eucJP/app-defaults
	$(INSTALL_DATA) $(WRKSRC)/resources/R6/EUC/EmiClock.ad \
			$(PREFIX)/lib/X11/ja_JP.eucJP/app-defaults/EmiClock

.include "../../mk/bsd.pkg.mk"
