# $NetBSD: Makefile,v 1.1 2002/06/22 17:56:38 kent Exp $

PKGNAME=	mpg123-esound-${MPG123_VERSION}
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with EsounD

TARGET_SUFFIX=	-esd
.include "../mpg123/Makefile.common"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpg123 ${PREFIX}/bin/mpg123-esound

.include "../esound/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
