# $NetBSD: Makefile,v 1.4 2007/06/11 13:38:47 markd Exp $

PKGNAME=	emacs-nox11-${EMACSVERSION}a
CATEGORIES=	editors
COMMENT_EXTRA=	: non-X11 version

CONFLICTS+=	emacs-[0-9]*

.include "../../mk/bsd.prefs.mk"

# Forcibly remove any "x11" options.
PKG_OPTIONS.emacs+=	-x11 -emacs-xaw3d -motif -xaw

.include "../../editors/emacs21/Makefile"
