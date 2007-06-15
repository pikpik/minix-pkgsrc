# $NetBSD: Makefile,v 1.7 2006/11/20 07:30:35 cjep Exp $
#

DISTNAME=		bsdiff-4.3
CATEGORIES=		misc
MASTER_SITES=		http://www.daemonology.net/bsdiff/

MAINTAINER=		cjep@NetBSD.org
HOMEPAGE=		http://www.daemonology.net/bsdiff/
COMMENT=		Size efficient binary diff and patch tools

USE_TOOLS+=		bzip2:run

MAKE_ENV+=		BZIP2=${BZIP2}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
