# $NetBSD: Makefile,v 1.1.1.1 1999/08/26 19:54:15 proff Exp $

DISTNAME=	ffcall-1.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.santafe.edu/pub/gnu/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://clisp.cons.org/~haible/packages-ffcall.html

# the file ${WRKDIR}/ffcall-1.6/avcall/avcall-${MACHINE_ARCH}.c needs to
# be added for additional port support.
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arm *-*-i386 *-*-m68k *-*-sparc *-*-sparc64

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
