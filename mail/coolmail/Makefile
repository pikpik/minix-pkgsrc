# $NetBSD$

DISTNAME=		coolmail-1.3
CATEGORIES=		mail x11
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/mail/biffs
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net

MAKE_ENV+=		X11BASE=${PREFIX}
USE_X11=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/Coolmail.ad \
	  ${PREFIX}/lib/X11/app-defaults/Coolmail

.include "../../mk/bsd.pkg.mk"
