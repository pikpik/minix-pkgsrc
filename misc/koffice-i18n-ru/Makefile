# $NetBSD: Makefile,v 1.7 2006/03/06 00:18:20 wiz Exp $

DISTNAME=	koffice-i18n-ru-1.3.5
PKGREVISION=	5
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.3.5/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://www.koffice.org/
COMMENT=	Russian language pack for KOffice

DEPENDS+=	kdelibs-[0-9]*:../../x11/kdelibs3

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/bsd.pkg.mk"
