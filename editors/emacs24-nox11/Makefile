# $NetBSD: Makefile,v 1.35 2012/02/20 01:22:32 obache Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}

CONFLICTS+=	emacs-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs24/files
PATCHDIR=	${.CURDIR}/../../editors/emacs24/patches
PKGDIR=		${.CURDIR}/../../editors/emacs24

.include "../../editors/emacs24/Makefile.common"

CONFIGURE_ARGS+=	--without-dbus --without-m17n-flt --without-otf \
			--without-rsvg --without-x --without-xft \
			--without-gif --without-jpeg --without-png \
			--without-tiff --without-xpm

.include "../../mk/bsd.pkg.mk"
