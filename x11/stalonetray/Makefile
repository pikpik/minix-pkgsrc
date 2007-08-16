# $NetBSD: Makefile,v 1.1 2007/08/04 13:44:20 smb Exp $
#
DISTNAME=stalonetray-0.6.5
CATEGORIES=x11
MASTER_SITES=${MASTER_SITE_SOURCEFORGE:=stalonetray/}

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://stalonetray.sourceforge.net/
COMMENT=	Stand-alone system tray

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-native-kde
USE_LANGUAGES+=	c

INSTALLATION_DIRS=	share/examples

post-install:
	${INSTALL_DATA} ${WRKSRC}/stalonetrayrc.sample ${DESTDIR}${PREFIX}/share/examples/stalonetray.rc

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
