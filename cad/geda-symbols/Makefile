# $NetBSD: Makefile,v 1.14 2004/01/22 07:21:54 grant Exp $
#

DISTNAME=	geda-symbols-${PKGVERSION}
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
		ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
		http://www.geda.seul.org/devel/${PKGVERSION}/ \
		http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Library of symbols for gEDA

CONFLICTS+=	gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make sed

.include "../../mk/bsd.pkg.mk"
