# $NetBSD: Makefile,v 1.4 2006/04/08 15:49:16 wiz Exp $
#

DISTNAME=		libmpd-0.15.0
CATEGORIES=		audio
MASTER_SITES=		http://download.qballcow.nl/gmpc-0.15.5/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cms.qballcow.nl/index.php?page=libmpd
COMMENT=		Library to access mpd (musicpd)

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libmpd.pc.in
USE_TOOLS+=		pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
