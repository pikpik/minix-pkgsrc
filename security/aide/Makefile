# $NetBSD: Makefile,v 1.6 2001/03/27 03:20:14 hubertf Exp $
#

DISTNAME=       aide-0.9
CATEGORIES=	security
MASTER_SITES=   http://www.cs.tut.fi/~rammer/ \
		ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	free intrusion detection system for checking file integrity

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS=	mhash>=0.8.17:../../security/mhash

USE_BUILDLINK2= # defined

GNU_CONFIGURE=	yes
#don't set YACC so configure can correctly find bison
YACC=

.include "../../security/mhash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
