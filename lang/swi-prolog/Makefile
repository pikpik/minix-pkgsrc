# $NetBSD: Makefile,v 1.40 2007/10/25 22:00:48 jlam Exp $

META_PACKAGE=		# empty

.include "../../lang/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-${SWIPLVERS}
CATEGORIES=		lang

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler suite

DEPENDS+=		swi-prolog-lite-${SWIPLVERS}{,nb[0-9]*}:../../lang/swi-prolog-lite
DEPENDS+=		swi-prolog-packages-${SWIPLVERS}{,nb[0-9]*}:../../lang/swi-prolog-packages

.include "../../mk/bsd.pkg.mk"
