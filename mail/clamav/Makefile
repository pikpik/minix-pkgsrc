# $NetBSD: Makefile,v 1.3 2003/06/07 17:39:15 jmmv Exp $

DISTNAME=	clamav-0.60
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clamav/}

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://clamav.elektrapro.com/
COMMENT=	Anti-virus toolkit

AUTOCONF_REQD=		2.53	# clamav used 2.53
USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
# disable the configure check for user and group:
CONFIGURE_ARGS+=	--disable-clamav
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-uid=${CLAMAV_USER}
CONFIGURE_ARGS+=	--with-group=${CLAMAV_GROUP}

BUILD_DEFS+=	CLAMAV_USER CLAMAV_GROUP

PKG_GROUPS+=    ${CLAMAV_GROUP}
PKG_USERS+=     ${CLAMAV_USER}:${CLAMAV_GROUP}::Clamav\\ User

EGDIR=		${PREFIX}/share/examples/clamav
CONF_FILES=	${EGDIR}/clamav.conf ${PKG_SYSCONFDIR}/clamav.conf

pre-configure:
	cd ${WRKSRC};						\
	${ACLOCAL};						\
	${AUTOMAKE} -a --foreign -i;				\
	${AUTOCONF}

# for freshclam to work it must own the share/clamav dir
post-install:
	${CHOWN} -R ${CLAMAV_USER}:${CLAMAV_GROUP} ${PREFIX}/share/examples/clamav

.include "../../devel/zlib/buildlink2.mk"
.include "../../mail/libmilter/buildlink2.mk"
.include "../../archivers/bzip2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
