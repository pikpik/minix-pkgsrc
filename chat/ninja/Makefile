# $NetBSD$
#

DISTNAME=	ninja-1.5.8.1
CATEGORIES=	irc
MASTER_SITES=	ftp://ninja.qoop.org/ninja/sources/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://ninja.qoop.org/
COMMENT=	Another irc client based on ircII

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
