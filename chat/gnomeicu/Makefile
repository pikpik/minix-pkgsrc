# $NetBSD: Makefile,v 1.5 2002/09/10 16:06:34 wiz Exp $

DISTNAME=	gnomeicu-0.96
PKGREVISION=	2
CATEGORIES=	chat gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnomeicu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://gnomeicu.sourceforge.net/
COMMENT=	GNOME ICQ client

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES

LIBS+=		-liconv

.include "../../databases/gdbm/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
