# $NetBSD: Makefile,v 1.5 2001/11/29 01:12:26 hubertf Exp $

DISTNAME=		irssi-0.8.1
CATEGORIES=		chat
MASTER_SITES=		http://www.irssi.org/files/

MAINTAINER=		mutru@cc.hut.fi
HOMEPAGE=		http://www.irssi.org/
COMMENT=                Secure and modular IRC client with text mode user interface

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-perl=no \
			--with-terminfo \
			--enable-ipv6
USE_BUILDLINK_ONLY=	yes
USE_CONFIG_WRAPPER=	yes

.include "../../devel/glib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
