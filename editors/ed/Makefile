# $NetBSD: Makefile,v 1.12 2010/01/27 18:20:43 joerg Exp $

DISTNAME=		ed-1.1
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GNU:=ed/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.gnu.org/software/ed/ed.html
COMMENT=		GNU version of line-oriented text editor
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

INFO_FILES=		yes

CONFIGURE_ARGS+=	--program-prefix=g

INSTALL_TARGET=		install install-man

INSTALLATION_DIRS=	gnu/bin

post-install:
	ln -s ../../bin/ged  ${DESTDIR}${PREFIX}/gnu/bin/ed
	ln -s ../../bin/gred ${DESTDIR}${PREFIX}/gnu/bin/red

.include "../../mk/bsd.pkg.mk"
