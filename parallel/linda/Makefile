# $NetBSD: Makefile,v 1.9 2004/02/14 17:21:49 jlam Exp $
#

DISTNAME=	linda-0.1.1
PKGREVISION=	4
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linda/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/linda/
COMMENT=	Parallel distributed database environment

GNU_CONFIGURE=		# defined
USE_BUILDLINK3=		YES
USE_LIBTOOL=		# defined

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
