# $NetBSD: Makefile,v 1.6 1998/08/20 15:16:40 tsarna Exp $
# FreeBSD Id: Makefile,v 1.9 1997/02/04 10:32:34 max Exp 
#

DISTNAME=	soxgamma
PKGNAME=	sox-12.16
CATEGORIES=	audio
MASTER_SITES=	http://metalab.unc.edu/pub/Linux/apps/sound/convert/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.spies.com/Sox/

NO_WRKSUBDIR=	yes
MAKEFILE=	Makefile.unx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sox ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sox.man ${PREFIX}/man/man1/sox.1

.include "../../mk/bsd.pkg.mk"
