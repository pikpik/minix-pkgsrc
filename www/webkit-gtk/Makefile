# $NetBSD: Makefile,v 1.45 2011/07/08 17:27:29 drochner Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkit/webkit-gtk/}

COMMENT=	GTK2 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=2.0

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
