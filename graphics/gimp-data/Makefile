# $NetBSD: Makefile,v 1.79 2002/02/13 19:50:05 drochner Exp $

DISTNAME=		gimp-data-extras-1.2.0
PKGNAME=		gimp-data-1.2
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/v1.2/v1.2.3/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v1.2/v1.2.3/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.2/v1.2.3/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gimp.org/
COMMENT=		extra brushes and patterns for the GIMP

CONFLICTS+=		gimp<=1.2.3

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes

.include "../../graphics/gimp-base/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
