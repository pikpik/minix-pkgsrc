# $NetBSD: Makefile,v 1.34 2001/10/18 15:20:11 veego Exp $
#

DISTFILES=	# empty
.include "Makefile.common"

PKGNAME=	${PKGPFX}
SVR4_PKGNAME=	ltool

DEPENDS+=	${PKGNAME:C/-/-base-/}:../libtool-base
DEPENDS+=	${PKGNAME:C/-/-info-/}:../libtool-info

COMMENT=	Generic shared library support script

NO_CONFIGURE=	yes
NO_PATCH=	yes
NO_BUILD=	yes

do-install:
	@${ECHO_MSG} this is only a meta package.

.include "../../mk/bsd.pkg.mk"
