# $NetBSD: Makefile,v 1.13 2004/11/22 14:51:05 adam Exp $

DISTNAME=	mhash-0.9.2
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mhash/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mhash.sourceforge.net/
COMMENT=	Hash algorithms library

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PERL5=		build
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
