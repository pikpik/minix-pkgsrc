# $NetBSD: Makefile,v 1.5 2001/06/11 06:34:55 jlam Exp $
#

DISTNAME=	gateway-0.8
PKGNAME=	kannel-0.8
CATEGORIES=	www net
MASTER_SITES=	http://www.kannel.org/download/0.8/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.kannel.org/
COMMENT=	open source WAP and SMS gateway

USE_BUILDLINK_ONLY=YES
USE_PERL5=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--disable-docs

.include "../../textproc/libxml/buildlink.mk"
.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
