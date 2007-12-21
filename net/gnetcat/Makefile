# $NetBSD: Makefile,v 1.7 2007/02/15 21:47:56 rillig Exp $

DISTNAME=	netcat-0.7.1
PKGNAME=	gnetcat-0.7.1
PKGREVISION=	2
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netcat/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://netcat.sourceforge.net/
COMMENT=	Read and write data across network connections

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
INFO_FILES=		yes
USE_TOOLS+=		msgfmt

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
