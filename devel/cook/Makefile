# $NetBSD: Makefile,v 1.3 2001/09/27 23:17:54 jlam Exp $

DISTNAME=	cook-2.17
CATEGORIES=	devel
MASTER_SITES=	http://www.canb.auug.org.au/~millerp/cook/

MAINTAINER=	groo@netbsd.org
HOMEPAGE=	http://www.canb.auug.org.au/~millerp/cook/cook.html
COMMENT=	More powerful replacement for the traditional make(1) tool

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=	# defined
GNU_CONFIGURE=	# defined

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/rx/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
