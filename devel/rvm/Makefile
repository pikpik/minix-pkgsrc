# $NetBSD: Makefile,v 1.2 2001/02/16 14:39:01 wiz Exp $
#

DISTNAME=	rvm-1.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rvm/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Recoverable Virtual Memory

DEPENDS+=	lwp>=1.6:../../devel/lwp

#LICENSE=	GPL

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_GMAKE=	YES

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
