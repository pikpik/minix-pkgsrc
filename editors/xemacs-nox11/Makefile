# $NetBSD: Makefile,v 1.20 2008/04/24 15:32:16 jlam Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}

FILESDIR=	${.CURDIR}/../../editors/xemacs/files
PATCHDIR=	${.CURDIR}/../../editors/xemacs/patches
PKGDIR=		${.CURDIR}/../../editors/xemacs

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.xemacs+=	-x11 -lucid
#PKG_OPTIONS.xemacs+=	-gtk -motif -xaw

.include "../../editors/xemacs/Makefile"
