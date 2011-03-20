# $NetBSD: Makefile,v 1.3 2006/11/19 09:36:15 wiz Exp $
#

DISTNAME=		vde-1.5.9
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vde/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vde.sourceforge.net/
COMMENT=		Virtual Distributed Ethernet tools
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM+=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
