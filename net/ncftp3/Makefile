# $NetBSD: Makefile,v 1.5 2001/04/24 20:39:37 zuntum Exp $

DISTNAME=	ncftp-3.0.3-src
PKGNAME=	ncftp3-3.0.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.ncftp.com/
COMMENT=	FTP replacement with advanced user interface

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
GNU_CONFIGURE=	yes
USE_BUILDLINK_ONLY=	yes

post-patch:
	@${MV} ${WRKSRC}/ncftp/pref.h ${WRKSRC}/ncftp/pref.h.in
	@${SED} -e "s:/etc/ncftp.firewall:${PREFIX}/etc/ncftp.firewall:" \
		< ${WRKSRC}/ncftp/pref.h.in > ${WRKSRC}/ncftp/pref.h

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
