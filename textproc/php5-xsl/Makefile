# $NetBSD: Makefile,v 1.13 2004/10/31 21:28:51 jdolecek Exp $

MODNAME=		xsl
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP5 extension for XSLT functions

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libxslt}

# build uses includes of the DOM extension, so need to extract that too
EXTRACT_ELEMENTS=	${DISTNAME}/ext/${MODNAME} ${DISTNAME}/ext/dom
WRKSRC=			${WRKDIR}/${DISTNAME}/ext/${MODNAME}

PHP_VERSION_REQD=	5
.include "../../lang/php/ext.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
