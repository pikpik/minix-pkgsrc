# $NetBSD: Makefile,v 1.1.1.1 1998/10/21 19:16:45 garbled Exp $

DISTNAME=		fftw-2.1.3
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.fftw.org/

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-shared
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386-hacks
.endif
USE_GMAKE=		yes
INFO_FILES=		fftw.info

post-install:
	@${RM} -f ${LOCALBASE}/lib/librfftw.la
	@${RM} -f ${LOCALBASE}/lib/libfftw.la

.include "../../mk/bsd.pkg.mk"
