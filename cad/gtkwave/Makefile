# $NetBSD: Makefile,v 1.16 2006/10/04 20:47:44 wiz Exp $
#

DISTNAME=		gtkwave-3.1.1
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkwave/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.nc.rr.com/gtkwave/
COMMENT=		Electronic waveform viewer

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
