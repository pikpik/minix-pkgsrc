# $NetBSD: Makefile,v 1.2 2011/12/17 10:15:48 sbd Exp $
#

DISTNAME=	algol68g-2.4.1
CATEGORIES=	lang
MASTER_SITES=	http://jmvdveer.home.xs4all.nl/

MAINTAINER=	olafs@cs.ru.nl
HOMEPAGE=	http://jmvdveer.home.xs4all.nl/algol.html
COMMENT=	Algol 68genie compiler
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=$(PREFIX)/share/doc/$(PKGBASE)
# Since it ignores configure flag currently, override it through make argument:
INSTALL_MAKE_FLAGS=	docdir=$(PREFIX)/share/doc/$(PKGBASE)

TEST_TARGET=	check

.include "options.mk"

.include "../../devel/readline/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
