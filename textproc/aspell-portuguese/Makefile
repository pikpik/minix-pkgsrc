# $NetBSD: Makefile,v 1.16 2012/04/05 02:58:24 sbd Exp $
#

DISTNAME=	aspell6-pt_PT-20070510-0
PKGNAME=	aspell-portuguese-20070510.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/pt_PT/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Portuguese language support for aspell

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
