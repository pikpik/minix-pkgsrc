# $NetBSD: Makefile,v 1.2 2000/10/15 10:29:33 simonb Exp $
#

DISTNAME=	mad-0.11.4b
PKGNAME=	madplay-0.11.4b
CATEGORIES=	audio
MASTER_SITES=	http://download.sourceforge.net/mad/

MAINTAINER=	simonb@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/mad/

GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
CONFIGURE_ARGS+=	--enable-fpm=i386
.elif (${MACHINE_ARCH} == "sparc")
CONFIGURE_ARGS+=	--enable-fpm=sparc
.endif

.include "../../mk/bsd.pkg.mk"
