# $NetBSD: Makefile,v 1.32 2004/10/03 00:13:33 tv Exp $
#

DISTNAME=	readline-5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cnswww.cns.cwru.edu/php/chet/readline/rltop.html
COMMENT=	GNU library that can recall and edit previous input

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

ALL_TARGET=		all-libtool
INSTALL_TARGET=		install-libtool

INFO_FILES=		history.info readline.info rluserman.info

.include "../../mk/bsd.pkg.mk"
