# $NetBSD: Makefile,v 1.2 2002/12/13 12:54:43 grant Exp $
#

DISTNAME=	ScrollZ-1.9
PKGNAME=	scrollz-1.9
CATEGORIES=	chat
MASTER_SITES=   http://scrollz.broken.com/source/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.scrollz.com/
COMMENT=        Advanced IRC client based on ircII client

BUILD_DEFS+=	USE_INET6

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
