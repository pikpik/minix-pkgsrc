# $NetBSD: Makefile,v 1.3 2001/03/08 10:21:08 wiz Exp $

DISTNAME=	sylpheed-0.3.23
CATEGORIES=	mail x11
MASTER_SITES=	http://sylpheed.good-day.net/sylpheed/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://sylpheed.good-day.net/index.cgi.en
COMMENT=	X based e-mail client

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-nls

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
