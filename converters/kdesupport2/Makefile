# $NetBSD$
#

DISTNAME=	kdesupport-2.1
CATEGORIES=	converters kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Mime support library for the KDE desktop

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/audiofile/ltconfig \
			${WRKSRC}/admin/ltconfig
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

CONFIGURE_ARGS=		"--with-extra-includes=${LOCALBASE}/include" \
			"--without-libuulib" \
			"--without-audiofile"

.include "../../mk/bsd.pkg.mk"
