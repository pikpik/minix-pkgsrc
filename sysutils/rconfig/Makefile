# $NetBSD: Makefile,v 1.37 2012/10/03 21:57:43 wiz Exp $

DISTNAME=	rconfig-0.47
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://rconfig.googlecode.com/files/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://code.google.com/p/rconfig/
COMMENT=	Manage configurations for many machines via rdist trees

DEPENDS+=	fping-[0-9]*:../../net/fping
DEPENDS+=	freerdist-[0-9]*:../../net/rdist6
DEPENDS+=	shmux-[0-9]*:../../sysutils/shmux

USE_TOOLS+=	perl:run pod2man pod2html

.include "../../mk/bsd.pkg.mk"
