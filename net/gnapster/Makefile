# $NetBSD: Makefile,v 1.19 2002/09/10 16:06:46 wiz Exp $

DISTNAME=	gnapster-1.5.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.faradic.net/~jasta/files/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.faradic.net/~jasta/programs.html
COMMENT=	simple client for the online mp3 community

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
