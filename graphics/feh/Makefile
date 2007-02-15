# $NetBSD: Makefile,v 1.29 2006/04/17 13:46:31 wiz Exp $
#

DISTNAME=	feh-1.3.4
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.linuxbrit.co.uk/downloads/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.linuxbrit.co.uk/feh/
COMMENT=	Advanced image viewer

DEPENDS+=	wget-[0-9]*:../../net/wget

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--program-transform-name=s,cam,feh_cam,
REPLACE_PERL=		cam/cam

BUILDLINK_API_DEPENDS.giblib+=	giblib>=1.2.4
BUILDLINK_API_DEPENDS.jpeg+=	jpeg>=6bnb3 # includes jpegint.h

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/giblib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
