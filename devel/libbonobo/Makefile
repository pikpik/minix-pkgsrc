# $NetBSD$

DISTNAME=		libbonobo-2.0.0
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.0/sources/libbonobo/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://developer.gnome.org/
COMMENT=		GNOME2 Object activation framework library

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/bonobo-activation/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
