# $NetBSD: Makefile,v 1.1.1.1 2002/12/13 09:39:15 salo Exp $
#

DISTNAME=	ifile-1.3.0
CATEGORIES=	mail
MASTER_SITES=	http://savannah.nongnu.org/download/ifile/default.pkg/${PKGVERSION}/

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCHFILES=	ifile-${PKGVERSION}.argp_configure.patch.gz

MAINTAINER=	salo@netbsd.org
HOMEPAGE=	http://www.nongnu.org/ifile/
COMMENT=	Intelligent mail filtering system

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include "../../mk/bsd.pkg.mk"
