# $NetBSD: Makefile,v 1.29 2013/02/06 23:22:54 jperkin Exp $
#

DISTNAME=	fbreader-sources-0.99.2
PKGNAME=	${DISTNAME:S/-sources//}
PKGREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	http://www.fbreader.org/files/desktop/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fbreader.org/
COMMENT=	Ebook reader software
LICENSE=	gnu-gpl-v2 AND modified-bsd

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

MAKE_ENV+=	INSTALLDIR=${PREFIX}
MAKE_ENV+=	DESTDIR=${DESTDIR}
MAKE_ENV+=	LDFLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib
MAKE_ENV+=	TARGET_ARCH=desktop

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "NetBSD"
CPPFLAGS+=	-DDO_ICONV_CAST
.endif

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/liblinebreak/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
