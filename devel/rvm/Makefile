# $NetBSD: Makefile,v 1.3 2001/04/27 19:01:55 phil Exp $
#

DISTNAME=	rvm-1.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rvm/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Recoverable Virtual Memory

#LICENSE=	GPL

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_GMAKE=	YES

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../devel/lwp/buildlink.mk"

CONFIGURE_ARGS+=	--with-lwp-includes=${BUILDLINK_INCDIR}
LDFLAGS+=		-L${BUILDLINK_LIBDIR}

pre-configure: ${BUILDLINK_TARGETS}

.include "../../mk/bsd.pkg.mk"
