# $NetBSD: Makefile,v 1.3 1998/01/19 00:50:56 hubertf Exp $
#

DISTNAME=	cam-1.02
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/mixers
EXTRACT_SUFX=	.tgz

# FreeBSD maintainer
MAINTAINER=	erich@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/libncurses.a:${PORTSDIR}/devel/ncurses

MAN1=		cam.1

.include "../../mk/bsd.pkg.mk"
