# $NetBSD: Makefile,v 1.12 1999/04/08 07:34:56 tron Exp $
#

# for OBJECT_FMT
.include "../../mk/bsd.prefs.mk"

DISTNAME=       mpg123-0.59q
CATEGORIES=	audio
MASTER_SITES=   http://ftp.tu-clausthal.de/pub/unix/audio/mpg123/

MAINTAINER=	augustss@cs.chalmers.se
HOMEPAGE=	http://mpg.123.org/

.if (${MACHINE_ARCH} == "i386")
.if (${OBJECT_FMT} == "ELF")
ALL_TARGET=	netbsd-i386-elf
.else
ALL_TARGET=	netbsd-i386
.endif
.elif (${MACHINE_ARCH} == "m68k")
ALL_TARGET=	netbsd-m68k
.else
ALL_TARGET=	netbsd
.endif

MAKE_FLAGS+=	PREFIX="${PREFIX}"

post-patch:
	${CP} ${FILESDIR}/decode_i586_.s ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
