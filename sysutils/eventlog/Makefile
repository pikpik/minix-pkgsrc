# $NetBSD: Makefile,v 1.12 2009/12/09 11:07:01 obache Exp $

VERS=		0.2.12
DISTNAME=	eventlog_${VERS}
PKGNAME=	eventlog-${VERS}
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/open-source-edition/3.2.4/source/
WRKSRC=		${WRKDIR}/${PKGNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.balabit.com/network-security/syslog-ng/
COMMENT=	Support library for syslog-ng
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

.include "../../mk/bsd.pkg.mk"
