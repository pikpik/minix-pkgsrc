# $NetBSD: Makefile,v 1.10 2006/02/05 23:08:29 joerg Exp $
#

DISTNAME=		rss2html-0.8
CATEGORIES=		converters
MASTER_SITES=		http://cvs.nopcode.org/ftp/rss2html/ \
			ftp://ftp.nopcode.org/prj/rss2html/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nopcode.org/blog/rss2html.html
COMMENT=		RSS to HTML converter

PKG_INSTALLATION_TYPES=	overwrite pkgviews
GNU_CONFIGURE=	YES
USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	bin

LIBS.SunOS+=		-lnsl -lsocket
MAKE_ENV+=		LIBS=${LIBS:M*:Q}

.include "../../mk/bsd.pkg.mk"
