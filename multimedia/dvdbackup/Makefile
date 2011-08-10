# $NetBSD: Makefile,v 1.6 2011/02/28 14:52:57 wiz Exp $

DISTNAME=	dvdbackup-0.4.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvdbackup/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdbackup.sourceforge.net/
COMMENT=	DVD backup utility
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
