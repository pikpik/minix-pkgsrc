# $NetBSD: Makefile,v 1.7 2003/03/28 21:14:12 wiz Exp $
#

DISTNAME=	gzip-1.2.4a
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	The "meta-package" for the GZIP compression utility

DEPENDS+=	gzip-base-1.2.4anb1:../../archivers/gzip-base
DEPENDS+=	gzip-info-1.2.4a:../../archivers/gzip-info

USE_BUILDLINK2=	YES

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
