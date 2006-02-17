# $NetBSD: Makefile,v 1.6 2006/01/04 04:29:07 schmonz Exp $
#

DISTNAME=		vs233
PKGNAME=		sr-examples-2.3.3
PKGREVISION=		1
CATEGORIES=		lang parallel
MASTER_SITES=		ftp://ftp.cs.arizona.edu/sr/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.cs.arizona.edu/sr/
COMMENT=		The SR language compiler and run time system

WRKSRC=			${WRKDIR}
NO_EXTRACT=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

### Use the second line below for installing if you want to make print-PLIST!
DOMOD=
#DOMOD=-pm

do-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/examples/sr
	cd ${PREFIX:Q}/share/examples/sr &&				\
	${PAX} -zr ${DOMOD} -f ${DISTDIR:Q}/${DISTFILES:Q}			\
		-s ,vsuite/examples,.,					\
		vsuite/examples

.include "../../mk/bsd.pkg.mk"
