# $NetBSD: Makefile,v 1.3 2006/02/05 23:11:28 joerg Exp $

MODNAME=	eaccelerator
PECL_VERSION=	0.9.5beta2
PECL_DISTNAME=	${MODNAME}-0.9.5-beta2
CATEGORIES+=	sysutils
COMMENT=	PHP accelerator, optimizer, encoder and dynamic content cache

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eaccelerator/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
