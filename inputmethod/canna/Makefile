# $NetBSD: Makefile,v 1.2 2003/09/23 15:06:57 uebayasi Exp $
#
.include "Makefile.common"

PKGNAME:=	Canna-${CANNA_VERSION}

DEPENDS+=	Canna-server>=${CANNA_VERSION}:../canna-server
DEPENDS+=	Canna-dict>=${CANNA_VERSION}:../canna-dict

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_BUILDLINK=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

CANNA_MODULE=	meta-package

do-patch:	# empty
do-install:	# empty

.include "../../mk/bsd.pkg.mk"
