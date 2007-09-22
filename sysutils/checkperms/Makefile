# $NetBSD: Makefile,v 1.11 2007/07/30 10:18:32 joerg Exp $
#

DISTNAME=	checkperms-1.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.schlechte-software.de/checkperms/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.schlechte-software.de/checkperms/
COMMENT=	Check and correct file permissions

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS_FROM_PLIST=	yes
USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

CHECK_PERMS=		no

.if ${OPSYS} == "Linux"
MAKE_ENV+=	NOGCCERROR=yes		# see PR 35930
.endif

.include "../../mk/bsd.pkg.mk"
