# $NetBSD: Makefile,v 1.3 2008/07/14 12:56:07 joerg Exp $

DISTNAME=	libhangul-0.0.8
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://kldp.net/frs/download.php/4618/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://kldp.net/projects/hangul/
COMMENT=	Library used by Korean input methods

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libhangul.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
