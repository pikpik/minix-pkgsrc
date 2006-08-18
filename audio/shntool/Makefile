# $NetBSD: Makefile,v 1.9 2004/06/24 23:50:54 ben Exp $
#

DISTNAME=	shntool-2.0.3
CATEGORIES=	audio archivers
MASTER_SITES=	http://www.etree.org/shnutils/shntool/source/

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://www.etree.org/shnutils/shntool/
COMMENT=	Lossless audio compressor wrapper tool

LICENSE=	no-commercial-use

GNU_CONFIGURE=	YES

# could also support: wav, OFR, LPAC and APE.
DEPENDS+=	shorten>=3.6.0:../../audio/shorten
DEPENDS+=	flac>=1.1.0:../../audio/shorten
DEPENDS+=	sox>=12.17.4:../../audio/sox

.include "../../mk/bsd.pkg.mk"
