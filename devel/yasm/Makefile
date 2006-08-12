# $NetBSD: Makefile,v 1.16 2006/04/13 18:27:24 jlam Exp $
#

DISTNAME=	yasm-0.5.0
CATEGORIES=	devel
MASTER_SITES=	http://www.tortall.net/projects/yasm/releases/

MAINTAINER=	shaun@inerd.com
HOMEPAGE=	http://www.tortall.net/projects/yasm/
COMMENT=	Complete rewrite of the NASM assembler with BSD license

USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
