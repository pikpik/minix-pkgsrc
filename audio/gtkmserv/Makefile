# $NetBSD: Makefile,v 1.16 2006/03/04 21:28:56 jlam Exp $
#

DISTNAME=	gtkmserv-0.5.2
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://projects.ubertechnique.com/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.ubertechnique.com/index.html
COMMENT=	Gtk-based GUI client for the audio/mserv package

PKG_DESTDIR_SUPPORt=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=		YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtkMserv ${DESTDIR}${PREFIX}/bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
