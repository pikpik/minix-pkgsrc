# $NetBSD: Makefile,v 1.26 2007/06/11 13:57:21 markd Exp $

PKGNAME=	emacs-nox11-${EMACSVERSION}
COMMENT_EXTRA=	: non-X11 version

CONFLICTS+=	emacs-[0-9]*

.include "../../mk/bsd.prefs.mk"

# Forcibly remove any "x11" options.
PKG_OPTIONS.emacs+=	-x11 -gtk -motif -xaw

.include "../../editors/emacs/Makefile"
