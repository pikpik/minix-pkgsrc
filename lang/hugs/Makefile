# New packages collection makefile for: hugs
# Version required:	1.4
# Date created:		22-Mar-98
# Whom:			nathanw@mit.edu
#
# $NetBSD: Makefile,v 1.1 1998/04/03 21:14:22 tron Exp $

DISTNAME=	hugs-January1998-source
PKGNAME=	hugs-1.4
CATEGORIES=	lang
MASTER_SITES=	ftp://haskell.org/pub/haskell/hugs/January1998/ \
		ftp://ftp.cs.nott.ac.uk/pub/haskell/hugs/January1998/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nathanw@mit.edu

WRKSRC=		${WRKDIR}/hugs/src
GNU_CONFIGURE=	yes
ALL_TARGET=	default
MAKE_ENV=	INSTALL="${INSTALL}" INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

post-extract:
	@${LN} -s ${FILESDIR}/configure ${WRKSRC}

.include <bsd.port.mk>
