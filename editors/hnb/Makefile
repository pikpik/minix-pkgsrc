# $NetBSD: Makefile,v 1.3 2003/05/02 11:54:45 wiz Exp $
#

DISTNAME=	hnb-1.8.1
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hnb/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://hnb.sourceforge.net/
COMMENT=	Hierarchical data organizer

INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]* NetBSD-1.6[A-U]-*

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_GMAKE=	yes

.include "../../devel/ncurses/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
