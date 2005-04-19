# $NetBSD: Makefile,v 1.5 2005/04/11 21:44:54 tv Exp $
#

DISTNAME=		libvisual-0.2.0
CATEGORIES=		audio graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://libvisual.sourceforge.net/
COMMENT=		Abstraction library between applications and audio visualisation plugins

USE_LIBTOOL=		yes
USE_X11=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libvisual.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
