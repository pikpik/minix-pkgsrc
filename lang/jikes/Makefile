# $NetBSD: Makefile,v 1.9 2002/03/31 17:55:21 dmcmahill Exp $
#

DISTNAME=	jikes-1.15
CATEGORIES=	lang
MASTER_SITES=	http://oss.software.ibm.com/pub/jikes/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www10.software.ibm.com/developerworks/opensource/jikes/
COMMENT=	Java source to byte-code compiler

ONLY_FOR_PLATFORM=	NetBSD-*-* SunOS-*-*

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_CXX=		yes
CXXFLAGS+=		${CFLAGS}
UNLIMIT_RESOURCES=      datasize

USE_GMAKE=	# uses multi-line comments with \ (naughty hack!)

.include "../../lang/gcc/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
