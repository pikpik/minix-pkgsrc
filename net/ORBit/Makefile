# $NetBSD: Makefile,v 1.10 1999/02/20 22:48:25 hubertf Exp $
#

DISTNAME=	ORBit-0.4.0
CATEGORIES=	corba
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/sources/gnome-1.0/sources/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/gnome-1.0/sources/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	glib-1.2.0:../../devel/glib
DEPENDS+=	gindent-1.9.1:../../devel/gindent

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

LIBTOOL_FLAGS=	--install-la
INFO_FILES=	libIDL.info

.include "../../mk/bsd.pkg.mk"
