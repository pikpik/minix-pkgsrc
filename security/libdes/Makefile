# $NetBSD$

DISTNAME=	libdes-4.04b
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.psy.uq.oz.au/pub/Crypto/DES/

MAINTAINER=	refling@comet.lbl.gov

CRYPTO=		YES

WRKSRC=         ${WRKDIR}/des

MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

.include "../../mk/bsd.pkg.mk"
