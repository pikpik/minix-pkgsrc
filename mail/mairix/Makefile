# $NetBSD: Makefile,v 1.12 2006/06/09 16:04:00 minskim Exp $
#

DISTNAME=		mairix-0.20
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mairix/}

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.rc0.org.uk/mairix/
COMMENT=		Program for indexing and searching email messages

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

USE_TOOLS+=		bison flex

.include "../../mk/bsd.pkg.mk"
