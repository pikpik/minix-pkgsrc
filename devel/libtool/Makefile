# $NetBSD: Makefile,v 1.9 1999/05/20 20:09:50 tron Exp $
#

DISTNAME=	libtool-1.3.3
# XXX should change back to libtool with next release; this differentiates
# libtool from pkg-customized libtool, the latter under the "libtool-1.2" name
PKGNAME=	glibtool-1.3.3
CATEGORIES=	devel
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
