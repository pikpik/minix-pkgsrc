# $NetBSD: Makefile,v 1.2 2000/01/20 15:24:37 hubertf Exp $
#

DISTNAME=		jwhois-2.4.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=jwhois/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/jwhois/

BUILD_DEPENDS+=		autoreconf:../../devel/autoconf
DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--sysconfdir=/etc
CONFIGURE_ARGS+=	--localstatedir=/var/db
CONFIGURE_ARGS+=	--with-cache
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include		# libintl.h

INFO_FILES=		jwhois.info

pre-configure:
	cd ${WRKSRC} && autoreconf

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/jwhois.conf ${PREFIX}/share/examples
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
