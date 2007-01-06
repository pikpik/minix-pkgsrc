# $NetBSD: Makefile,v 1.12 2006/05/20 18:30:09 joerg Exp $
#

DISTNAME=		MyPasswordSafe-20061216
CATEGORIES=		security
MASTER_SITES=		http://www.semanticgap.com/myps/release/
DISTFILES=		${DISTNAME}.src.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.semanticgap.com/myps/
COMMENT=		Easy-to-use password manager

.include "options.mk"

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
MAKE_FLAGS+=		QMAKE=${QTDIR:Q}/bin/qmake

.include "../../mk/bsd.pkg.mk"
