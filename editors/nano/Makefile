# $NetBSD: Makefile,v 1.2 2001/05/18 23:54:09 jtb Exp $

DISTNAME=	nano-1.0.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=nano/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/nano/nano.html
COMMENT=	small and friendly text editor (a free replacement for Pico)

GNU_CONFIGURE=		yes

#USE_LIBINTL=		yes
USE_BUILDLINK_ONLY=	yes

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
