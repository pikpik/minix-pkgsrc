# $NetBSD: Makefile,v 1.5 2000/01/19 17:36:51 tron Exp $

DISTNAME=	opendis-0.0.3
CATEGORIES=	graphics
MASTER_SITES=	http://ods.sourceforge.net/dl/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://ods.sourceforge.net/

#USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
