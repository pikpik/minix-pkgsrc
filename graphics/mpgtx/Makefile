# $NetBSD: Makefile,v 1.5 2003/07/17 21:41:50 grant Exp $
#

DISTNAME=	mpgtx-1.3
CATEGORIES=	audio graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpgtx/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mpgtx.sourceforge.net/
COMMENT=	Split and join MPEG files in various ways

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}	\
			--manprefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
