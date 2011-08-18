# $NetBSD: Makefile,v 1.17 2010/04/05 00:49:07 jakllsch Exp $

DISTNAME=		avr-libc-1.6.7
PKGREVISION=		2
CATEGORIES=		cross
MASTER_SITES=		http://savannah.nongnu.org/download/avr-libc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://savannah.nongnu.org/projects/avr-libc
COMMENT=		C and math library for Atmel AVR 8-bit microcontrollers

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		avr-binutils-[0-9]*:../../cross/avr-binutils
BUILD_DEPENDS+=		avr-gcc-[0-9]*:../../cross/avr-gcc

USE_TOOLS+=		gmake
USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST= no
CONFIGURE_ENV+=		AS=${PREFIX}/bin/avr-as
CONFIGURE_ENV+=		AR=${PREFIX}/bin/avr-ar
CONFIGURE_ENV+=		RANLIB=${PREFIX}/bin/avr-ranlib
CONFIGURE_ENV+=		CC=${PREFIX}/bin/avr-gcc
CONFIGURE_ARGS+=	--build=${MACHINE_GNU_PLATFORM:Q} --host=avr

PLIST_SRC=		${.CURDIR}/PLIST

.include "options.mk"

.include "../../mk/bsd.pkg.mk"

# XXX: very evil hack to override CC, doing it via CONFIGURE_ENV doesn't work.
ALL_ENV+= CC=${PREFIX}/bin/avr-gcc
