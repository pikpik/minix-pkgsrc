# $NetBSD: Makefile,v 1.9 2005/05/22 20:07:46 jlam Exp $

DISTNAME=		sqlrelay-0.33.1
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlrelay/}

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://sqlrelay.sourceforge.net/
COMMENT=		Enables pooling and sharing of database connections

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

.include "options.mk"

.include "../../devel/rudiments/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
