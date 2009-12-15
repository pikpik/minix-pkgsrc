# $NetBSD: Makefile,v 1.44 2005/07/19 10:20:07 grant Exp $

META_PACKAGE=	# empty

.include "Makefile.common"

SVR4_PKGNAME=	ltool

DEPENDS+=	${DISTNAME:S/-/-base-/}{,nb[0-9]*}:../../devel/libtool-base
DEPENDS+=	${DISTNAME:S/-/-info-/}{,nb[0-9]*}:../../devel/libtool-info

# There is no libltdl dependency here; this is deliberate, so that libltdl
# can be updated independently of the rest of libtool.

COMMENT=	Generic shared library support script

.include "../../mk/bsd.pkg.mk"
