# $NetBSD: Makefile,v 1.6 2007/06/11 13:38:27 markd Exp $

DISTNAME=	emacs-${EMACSVERSION}a
PKGREVISION=	11
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor)

.include "../../editors/emacs21/Makefile.common"

USE_TOOLS+=	imake

CONFLICTS+=	emacs-nox11-[0-9]*

CONFIGURE_ARGS+=	--srcdir=${WRKSRC:Q}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
