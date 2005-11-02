# $NetBSD: Makefile,v 1.5 2005/11/01 18:42:46 tv Exp $
#

DISTNAME=	sipcalc-1.1.2
CATEGORIES=	net
MASTER_SITES=	http://www.routemeister.net/projects/sipcalc/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.routemeister.net/projects/sipcalc/
COMMENT=	IPv4/IPv6 subnet calculator

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-web

PKG_OPTIONS_VAR=		PKG_OPTIONS.sipcalc
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
