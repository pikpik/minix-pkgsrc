# $NetBSD$

DISTNAME=		fftw-2.0.1
CATEGORIES=		math
MASTER_SITES=		ftp://theory.lcs.mit.edu/pub/fftw/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://theory.lcs.mit.edu/~fftw

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
INFO_FILES=		fftw.info

post-install:
	@${RM} -f ${LOCALBASE}/lib/librfftw.la
	@${RM} -f ${LOCALBASE}/lib/libfftw.la

.include "../../mk/bsd.pkg.mk"
