# $NetBSD: Makefile,v 1.6 2002/03/13 17:37:38 fredb Exp $

MODNAME=		pdf
PKGNAME=		php-pdflib-${PHP_BASE_VERS}
PKGREVISION=		1
CATEGORIES+=		print
PKGREVISION=		# empty
COMMENT=		PHP4 extension for PDFlib on-the-fly PDF generation

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}
CONFIGURE_ARGS+=	--with-jpeg-dir=shared,${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-png-dir=shared,${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-tiff-dir=shared,${BUILDLINK_PREFIX.tiff}
CONFIGURE_ENV+=		PHP_ZLIB_DIR=${BUILDLINK_PREFIX.zlib}

.include "../../print/pdflib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
