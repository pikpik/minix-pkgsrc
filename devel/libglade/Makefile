# $NetBSD: Makefile,v 1.35 2002/03/13 17:36:51 fredb Exp $
#

DISTNAME=		libglade-0.17
PKGREVISION=		1
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/libglade/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.daa.com.au/~james/gnome/
COMMENT=		Runtime interpreter for GLADE gui files

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-configure:
	${RM} ${WRKSRC}/libgladeConf.sh

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../audio/esound/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
