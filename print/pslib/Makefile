# $NetBSD: Makefile,v 1.2 2005/08/24 19:05:14 kristerw Exp $
#

DISTNAME=		pslib-0.2.6
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pslib/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pslib.sourceforge.net/
COMMENT=		C-library to create PostScript files

BUILD_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

BUILD_USES_MSGFMT=	yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libps.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		perl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
