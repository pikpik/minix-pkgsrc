# $NetBSD: Makefile,v 1.4 2002/12/27 08:41:25 uebayasi Exp $
#
.include "Makefile.common"

CANNA_MODULE=	server

DEPENDS+=	Canna-server-bin>=${CANNA_VERSION}:../canna-server-bin
DEPENDS+=	Canna-dict>=${CANNA_VERSION}:../canna-dict

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_BUILD=	YES

do-patch:	# empty
do-install:	# empty

.include "../../mk/bsd.pkg.mk"
