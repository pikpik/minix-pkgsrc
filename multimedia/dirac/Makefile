# $NetBSD: Makefile,v 1.6 2008/06/12 02:14:38 joerg Exp $
#

DISTNAME=		dirac-1.0.2
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dirac/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dirac.sourceforge.net/
COMMENT=		Open-source video codec designed at the BBC

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	dirac.pc.in

.include "../../mk/bsd.pkg.mk"
