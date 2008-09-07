# $NetBSD: Makefile,v 1.7 2008/07/14 12:55:56 joerg Exp $
#

DISTNAME=	libdca-0.0.5
CATEGORIES=	audio
MASTER_SITES=	http://download.videolan.org/pub/videolan/libdca/0.0.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://www.videolan.org/developers/libdca.html
COMMENT=	DTS Coherent Acoustics decoder

PKG_DESTDIR_SUPPORT=	user-destdir

RESTRICTED=	Unresolved patent issue
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
