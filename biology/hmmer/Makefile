# $NetBSD: Makefile,v 1.5 2004/08/16 02:47:49 ben Exp $
#

DISTNAME=		hmmer-2.3.2
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.genetics.wustl.edu/pub/eddy/hmmer/2.3.2/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://hmmer.wustl.edu/
COMMENT=		Implementation of profile HMM software for protein sequence analysis

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

MAKE_FLAGS+=            MKDIR="${MKDIR}"

.include "../../mk/bsd.pkg.mk"
