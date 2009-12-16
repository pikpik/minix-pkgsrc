# $NetBSD: Makefile,v 1.16 2008/06/14 08:58:06 tron Exp $

PKGNAME=	libmilter-${DIST_VERS}
PKGREVISION=	1
COMMENT=	Mail filter support library for sendmail

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"
.include "../../mail/sendmail/Makefile.common"

INSTALLATION_DIRS=	include lib

post-patch: make-sendmail-siteconfig

do-build:
	(cd ${WRKSRC}/libmilter && env ${MAKE_ENV} ./Build)

do-install:
	(cd ${WRKSRC}/libmilter && env ${MAKE_ENV} ./Build BINOWN=${BINOWN} BINGRP=${BINGRP} SHAREOWN=${SHAREOWN} SHAREGRP=${SHAREGRP} INCLUDEDIR=${DESTDIR}${PREFIX}/include LIBDIR=${DESTDIR}${PREFIX}/lib install)

PTHREAD_OPTS+=	require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# has to be below include for bsd.pkg.mk, else substition fails
OBJDIR!=	${ECHO} obj.`${UNAME} -srm | ${TR} \  .`
