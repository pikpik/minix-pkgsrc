# $NetBSD: Makefile,v 1.6 2008/06/20 01:09:12 joerg Exp $

DISTNAME=	gettext-0.14.6
PKGNAME=	gettext-asprintf-0.14.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gettext/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gettext/gettext.html
COMMENT=	Provides a printf-like interface for C++

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_DIRS=		gettext-runtime
BUILD_DIRS=		gettext-runtime/libasprintf

INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
