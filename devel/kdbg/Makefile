# $NetBSD: Makefile,v 1.10 2000/06/01 11:23:21 rh Exp $

DISTNAME=	kdbg-1.0.1
CATEGORIES=	devel kde
MASTER_SITES=	http://members.telecom.at/~johsixt/ \
		ftp://ftp.eudaptics.co.at/pub/people/jsixt/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=       http://members.telecom.at/~johsixt/kdbg.html

BUILD_DEPENDS+= ${LOCALBASE}/bin/msgfmt:../../devel/gettext
DEPENDS+=	autoconf-2.13:../autoconf
DEPENDS+=	automake-1.4:../automake
DEPENDS+=	kdevelop-1.*:../kdevelop
DEPENDS+=	png>=1.0.6:../../graphics/png

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_PKGLIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-dir=`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1 \
		--with-qt-includes=`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1/include \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-extra-includes=${LOCALBASE}/include

CONFIGURE_ENV=	KDEDIR=${PREFIX}

.include "../../mk/bsd.pkg.mk"
