# $NetBSD: Makefile,v 1.11 2004/03/26 02:27:52 wiz Exp $
#

DISTNAME=	kssh-0.7
PKGREVISION=	7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kssh/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://kssh.sourceforge.net/
COMMENT=	KDE Front-end to SSH

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../net/kdenetwork3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
