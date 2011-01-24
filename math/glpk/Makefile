# $NetBSD: Makefile,v 1.29 2010/07/13 06:46:56 adam Exp $

DISTNAME=	glpk-4.45
CATEGORIES=	math
MASTER_SITES=	$(MASTER_SITE_GNU:=glpk/)

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/glpk/glpk.html
COMMENT=	Library for solving linear programming problems

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
