# $NetBSD: Makefile,v 1.1.1.1 2001/03/14 16:13:03 skrll Exp $
#

DISTNAME=	quanta-2.0-pr1
PKGNAME=	quanta-2.0pr1
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quanta/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://quanta.sourceforge.net/
COMMENT= 	HTML editor suitable for experienced web developers

DEPENDS+=	kdebase>=2.1:../../x11/kdebase2

WRKSRC=		${WRKDIR}/quanta

.include "../../x11/kde2/Makefile.part2"

.include "../../mk/bsd.pkg.mk"
