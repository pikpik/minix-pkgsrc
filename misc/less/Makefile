# $NetBSD: Makefile,v 1.7 2003/02/17 12:54:25 grant Exp $
#

DISTNAME=       less-381
PKGREVISION=	1
CATEGORIES=     misc
MASTER_SITES=   http://www.greenwoodsoftware.com/less/ \
		${MASTER_SITE_GNU:=less/}

MAINTAINER=     bouyer@netbsd.org
HOMEPAGE=       http://www.greenwoodsoftware.com/less/
COMMENT=	pager similar to more and pg

GNU_CONFIGURE=  	yes
USE_BUILDLINK2=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
