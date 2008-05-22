# $NetBSD: Makefile,v 1.14 2008/03/08 13:49:10 joerg Exp $

DISTNAME=	ccache-2.4
CATEGORIES=	devel
MASTER_SITES=	http://samba.org/ftp/ccache/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ccache.samba.org/
COMMENT=	Cache for C/C++ compilers

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

CCACHE_DEFAULT_MAXSIZE?=	1048576
BUILD_DEFS+=			CCACHE_DEFAULT_MAXSIZE
CPPFLAGS+=			-DDEFAULT_MAXSIZE=${CCACHE_DEFAULT_MAXSIZE}

.include "../../mk/bsd.pkg.mk"
