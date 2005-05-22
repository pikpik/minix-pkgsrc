# $NetBSD: Makefile,v 1.52 2005/04/11 21:45:18 tv Exp $

DISTNAME=		bison-2.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=bison/}

MAINTAINER=		cjep@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/bison/bison.html
COMMENT=		GNU yacc(1) replacement

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_USES_MSGFMT=	yes
GNU_CONFIGURE=		YES
USE_TOOLS+=		gm4
TOOLS_DEPMETHOD.gm4=	DEPENDS

INFO_FILES=		bison.info

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
