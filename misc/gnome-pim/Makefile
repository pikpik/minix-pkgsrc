# $NetBSD: Makefile,v 1.16 2000/05/30 21:08:25 drochner Exp $
#

DISTNAME=		gnome-pim-1.2.0
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-pim/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/

BUILD_DEPENDS=		${LOCALBASE}/bin/bison:../../devel/bison
DEPENDS+=		gnome-core-*:../../x11/gnome-core

USE_X11BASE=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		LOCALEBASE=${LOCALEBASE}

PLIST_SUBST+=		LOCALEBASE=${LOCALEBASE}

.include "../../mk/bsd.prefs.mk"

# The directory in which locale files are found is:
#
#	${PREFIX}/${LOCALEBASE}/locale/<lang>/LC_MESSAGES
#
.if ${OPSYS} == "SunOS"
LOCALEBASE=		lib
.else
LOCALEBASE=		share
.endif

.include "../../mk/bsd.pkg.mk"
