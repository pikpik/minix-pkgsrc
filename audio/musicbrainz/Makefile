# $NetBSD: Makefile,v 1.6 2004/01/22 07:15:00 grant Exp $

DISTNAME=	libmusicbrainz-2.0.2
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.musicbrainz.org/
COMMENT=	Second generation incarnation of the CD Index

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	libmusicbrainz.pc.in

CONFIGURE_ARGS+=	--enable-cpp-headers

.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
