# $NetBSD: Makefile,v 1.4 2012/11/29 07:19:35 wen Exp $

DISTNAME=	mosh-1.2.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/downloads/keithw/mosh/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://mosh.mit.edu/
COMMENT=	Remote terminal application which allows roaming
LICENSE=	gnu-gpl-v3

DEPENDS+=       p5-IO-tty>=1.08:../../devel/p5-IO-Tty

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

REPLACE_PERL+=	scripts/mosh

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=    zlib>=1.2.0.4
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
