# $NetBSD: Makefile,v 1.32 2001/02/16 14:38:40 wiz Exp $
#

DISTFILES=	# empty
.include "Makefile.common"

PKGNAME=	${PKGPFX}${PKGREV}

DEPENDS+=	${PKGPFX:C/-/-base-/}${PKGREV}:../libtool-base
DEPENDS+=	${PKGPFX:C/-/-info-/}${PKGREV}:../libtool-info

COMMENT=	Generic shared library support script

NO_CONFIGURE=	yes
NO_PATCH=	yes
NO_BUILD=	yes

do-install:
	@${ECHO_MSG} this is only a meta package.

.include "../../mk/bsd.pkg.mk"
