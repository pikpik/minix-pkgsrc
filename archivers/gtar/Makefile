# $NetBSD: Makefile,v 1.25 2004/05/18 11:58:04 recht Exp $

DISTNAME=	gtar-1.14
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The "meta-package" for the GNU tape archiver (tar)

DEPENDS+=	gtar-base-1.14:../../archivers/gtar-base
DEPENDS+=	gtar-info-1.14:../../archivers/gtar-info

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILDLINK=	yes

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
