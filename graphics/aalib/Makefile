# $NetBSD: Makefile,v 1.1.1.1 2001/09/08 23:03:02 manu Exp $
#

DISTNAME=	aalib-1.4rc4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aa-project/}

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://aa-project.sourceforge.net/aalib/
COMMENT=	ASCII Art library

WRKSRC=		${WRKDIR}/aalib-1.4.0
GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
