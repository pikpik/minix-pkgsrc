# $NetBSD: Makefile,v 1.7 2001/06/11 06:34:31 jlam Exp $
#

DISTNAME=	bvi-1.2.0.src
PKGNAME=	bvi-1.2.0
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	editors
MASTER_SITES=	http://bvi.linuxave.net/download/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://bvi.linuxave.net/
COMMENT=	Display-oriented editor for binary files, based on the vi editor

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
MAKE_ENV+=		SHELL=${SH}

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
