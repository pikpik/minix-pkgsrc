# $NetBSD: Makefile,v 1.3 2002/08/25 21:52:09 jlam Exp $
#

DISTNAME=	elinks-0.3.0
CATEGORIES=	www
MASTER_SITES=	http://elinks.or.cz/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://elinks.or.cz/
COMMENT=	Extended/Enhanced Links (elinks)

CONFLICTS=	links-[0-9]* links-gui-[0-9]*

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
