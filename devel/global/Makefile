# $NetBSD: Makefile,v 1.22 2006/03/30 03:44:43 jlam Exp $
#

DISTNAME=	global-5.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=global/} \
		http://tamacom.com/global/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/global/
COMMENT=	Source code tag system including web browser output

PKG_INSTALLATION_TYPES=	overwrite pkgviews
GNU_CONFIGURE=		YES
INFO_FILES=		YES
USE_TOOLS+=		perl:run

.include "../../mk/bsd.pkg.mk"
