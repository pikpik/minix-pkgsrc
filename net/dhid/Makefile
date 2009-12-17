# $NetBSD: Makefile,v 1.19 2006/03/04 21:30:17 jlam Exp $
#

DISTNAME=	dhid-5.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dhis.org/
COMMENT=	Dynamic Host Information System client daemon

RCD_SCRIPTS=	dhid

INSTALLATION_DIRS=	sbin share/doc/dhid
PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhid ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/genkeys ${DESTDIR}${PREFIX}/sbin/dhid-genkeys
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DESTDIR}${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${DESTDIR}${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dhid

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
