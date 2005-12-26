# $NetBSD: Makefile,v 1.19 2005/06/01 18:03:22 jlam Exp $
#

DISTNAME=		medusa-0.5.1
PKGREVISION=		7
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/medusa/0.5/}	\
			http://download.eazel.com/source/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.eazel.com/
COMMENT=		File system indexing engine

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

DEPENDS+=		psmisc-[0-9]*:../../sysutils/psmisc

GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
