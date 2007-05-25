# $NetBSD: Makefile,v 1.35 2006/03/31 05:37:08 jlam Exp $
#

DISTNAME=	htop-0.6.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://htop.sourceforge.net/
COMMENT=	Enhanced version of top utility

GNU_CONFIGURE=	yes
USE_NCURSES=	yes # uses ncurses mouse definitions

.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
