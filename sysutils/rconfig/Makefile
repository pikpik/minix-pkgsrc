# $NetBSD: Makefile,v 1.23 2004/06/22 06:31:46 abs Exp $

DISTNAME=	rconfig-0.34
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mono.org/abs/tools/rconfig/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.mono.org/abs/tools/rconfig/
COMMENT=	Manage configurations for many machines via rdist trees

DEPENDS+=	fping-[0-9]*:../../net/fping
DEPENDS+=	freerdist-[0-9]*:../../net/rdist6

USE_PERL5=	# defined

.include "../../mk/bsd.pkg.mk"
