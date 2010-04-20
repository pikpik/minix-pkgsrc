# $NetBSD: Makefile,v 1.20 2007/12/02 00:11:10 wiz Exp $
#

DISTNAME=	mawk-1.3.4
PKGNAME=	${DISTNAME:S/-20/.20/}
CATEGORIES=	lang
MASTER_SITES=	ftp://invisible-island.net/mawk/
EXTRACT_SUFX=  .tgz

MAINTAINER=	vle@gmx.net
COMMENT=	AWK clone by Mike Brennan
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=   user-destdir

INSTALLATION_DIRS=	${PKGMANDIR}/man1

GNU_CONFIGURE=	yes

TEST_TARGET=	mawk_test fpe_test
PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

# mawk configure fails with -ffast-math
CFLAGS:=	${CFLAGS:S/-ffast-math//}

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
