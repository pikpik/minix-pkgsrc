# $NetBSD: Makefile,v 1.7 1998/11/21 17:02:16 tron Exp $
#

DISTNAME=	ORBit-0.3.90
CATEGORIES=	corba
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/ORBit/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	glib-1.1.9:../../devel/glib
DEPENDS+=	gindent-1.9.1:../../devel/gindent

CONFLICTS=	ORBit-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

LIBTOOL_FLAGS=	--install-la
INFO_FILES=	libIDL.info

.include "../../mk/bsd.pkg.mk"
