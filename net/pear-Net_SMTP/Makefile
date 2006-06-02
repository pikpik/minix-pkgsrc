# $NetBSD: Makefile,v 1.4 2006/02/05 23:10:29 joerg Exp $

DISTNAME=	Net_SMTP-1.2.6
CATEGORIES+=	net mail

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to provide SMTP Interface

CONFLICTS=	php-pear-Net_SMTP-[0-9]

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.2:../../net/pear-Net_Socket

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
