# $NetBSD: Makefile,v 1.6 1998/08/20 15:17:28 tsarna Exp $
# FreeBSD Id: Makefile,v 1.12 1997/07/17 19:29:07 andreas Exp
#

DISTNAME=       glimpse-4.1.src
PKGNAME=	glimpse-4.1
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	textproc databases
MASTER_SITES=   ftp://ftp.cs.arizona.edu/glimpse/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://glimpse.cs.arizona.edu/

NO_CDROM=	"Restrictive copyright (don't sell for profit)"
GNU_CONFIGURE=	yes

pre-configure:
	chmod ugo+x ${WRKSRC}/configure

post-configure:
	${CP} -f ${FILESDIR}/autoconf.h \
		 ${WRKSRC}/libtemplate/include/autoconf.h

post-install:
	${MKDIR} ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glimpse
	${INSTALL_PROGRAM} ${WRKSRC}/index/wgconvert ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
