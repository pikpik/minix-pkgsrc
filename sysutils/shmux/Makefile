# $NetBSD: Makefile,v 1.1.1.1 2003/06/24 00:32:03 hubertf Exp $

DISTNAME=	shmux-0.10a
CATEGORIES=	sysutils
MASTER_SITES=	http://web.taranis.org/shmux/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shmux@taranis.org
HOMEPAGE=	http://web.taranis.org/shmux/
COMMENT=	Shell Multiplexor

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	shmux

.include "../../devel/pcre/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
