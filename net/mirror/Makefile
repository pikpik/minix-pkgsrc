# $NetBSD: Makefile,v 1.6 1998/06/22 12:58:34 agc Exp $
# FreeBSD Id: Makefile,v 1.6 1996/12/01 01:22:54 obrien Exp 
#

DISTNAME=	mirror-2.8
CATEGORIES=	net
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	packages@netbsd.org

USE_PERL5=	yes

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile

pre-install:
	${MKDIR} ${PREFIX}/lib/mirror

.include "../../mk/bsd.pkg.mk"
