# $NetBSD: Makefile,v 1.8 2005/08/18 15:46:23 taca Exp $
#

DISTNAME=	chasen-${CHASEN_VERSION}
CATEGORIES=	japanese textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://chasen-legacy.sourceforge.jp/
COMMENT=	meta package of ChaSen, Japanese Morphological Analysis System

DEPENDS+=	chasen-base>=${CHASEN_VERSION}:../../textproc/chasen-base
DEPENDS+=	ipadic>=2.6.3:../../textproc/ipadic

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:	# empty

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
