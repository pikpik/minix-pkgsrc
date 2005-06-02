# $NetBSD: Makefile,v 1.9 2005/04/11 21:45:05 tv Exp $
#

DISTNAME=	ScrollZ-1.9
PKGNAME=	scrollz-1.9
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.scrollz.com/pub/ScrollZ/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.scrollz.com/
COMMENT=	Advanced IRC client based on ircII client

GNU_CONFIGURE=	yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.scrollz
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
