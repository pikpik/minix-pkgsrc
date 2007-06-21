# $NetBSD: Makefile,v 1.15 2006/09/09 02:41:58 obache Exp $
#

DISTNAME=	mined-2000.13.2
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://towo.net/mined/
COMMENT=	Html-aware editor

MAKE_FILE=	makefile

post-install:
		${CHMOD} -x ${PREFIX}/share/mined/conf_user/xinitrc.mined

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
