# $NetBSD: Makefile,v 1.5 2001/01/21 20:42:17 tron Exp $

DISTNAME=	zlib-1.1.3
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.freesoftware.com/pub/infozip/zlib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	ftp://ftp.freesoftware.com/pub/infozip/zlib/index.html

ONLY_FOR_PLATFORM=	SunOS-*-* # in base NetBSD system

.include "../../mk/bsd.prefs.mk"
.if exists(${LOCALBASE}/bin/libtool)
USE_LIBTOOL=	yes
MAKEFILE=	lt.mk
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

post-extract:
	${CP} ${FILESDIR}/lt.mk ${WRKSRC}
	${SED} \
		-e '/libz_pic.a/d' \
		-e '/libz_p.a/d' \
		<${PKGDIR}/PLIST >${PLIST_SRC}

.else
MAKEFILE=	bsd.mk
.endif

MAKE_ENV+=	NOLINT=yes

.include "../../mk/bsd.pkg.mk"
