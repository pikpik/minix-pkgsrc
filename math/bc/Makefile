# $NetBSD: Makefile,v 1.7 2006/04/05 23:01:15 jlam Exp $

DISTNAME=	bc-1.06
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=bc/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.gnu.org/software/bc/bc.html
COMMENT=	Arbitrary precision calculator language

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		flex
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline
INFO_FILES=		# PLIST

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
