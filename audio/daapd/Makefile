# $NetBSD: Makefile,v 1.1.1.1 2004/06/05 19:07:51 nathanw Exp $

DISTNAME=		daapd-0.2.2b
CATEGORIES=		audio
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tgz

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.deleet.de/projekte/daap/daapd/
COMMENT=		Server for DAA protocol (iTunes)

USE_LANGUAGES=		c c++
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
MAKEFILE=		makefile

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
