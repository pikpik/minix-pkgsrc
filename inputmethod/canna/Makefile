# $NetBSD: Makefile,v 1.1 2003/05/31 07:24:38 uebayasi Exp $
#
.include "Makefile.common"

PKGNAME:=	Canna-${CANNA_VERSION}

DEPENDS+=	Canna-server>=${CANNA_VERSION}:../canna-server
DEPENDS+=	Canna-dict>=${CANNA_VERSION}:../canna-dict

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_BUILD=	YES

do-patch:	# empty
do-install:	# empty

.include "../../mk/bsd.pkg.mk"
