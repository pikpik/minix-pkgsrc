# $NetBSD: Makefile,v 1.2 2002/08/25 21:49:57 jlam Exp $
#

DISTNAME=		gnet-1.1.7
CATEGORIES=		net
MASTER_SITES=		http://www.gnetlibrary.org/src/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnetlibrary.org/
COMMENT=		simple network library

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
CONFIGURE_ARGS=		--enable-glib2

.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
