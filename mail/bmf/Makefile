# $NetBSD: Makefile,v 1.9 2006/03/04 21:29:57 jlam Exp $
#

DISTNAME=	bmf-0.9.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bmf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/bmf/
COMMENT=	Self contained and extremely efficient Bayesian mail filter

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

CONFIGURE_ARGS+=	--without-mysql
MAKE_ENV+=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
