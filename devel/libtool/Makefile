# $NetBSD: Makefile,v 1.10 1999/09/02 21:35:50 christos Exp $
#

DISTNAME=	libtool-1.3.4
CATEGORIES=	devel pkgtools
MASTER_SITES=	${MASTER_SITE_GNU:=libtool/}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.profitpress.com/libtool/

GNU_CONFIGURE=	yes
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS=	--disable-shared
.endif
.else
CONFIGURE_ARGS=	--enable-ltdl-install
.endif

.include "../../mk/bsd.pkg.mk"
