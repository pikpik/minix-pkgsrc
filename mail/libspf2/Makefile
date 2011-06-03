# $NetBSD: Makefile,v 1.7 2009/09/08 10:36:27 tron Exp $

DISTNAME=	libspf2-1.2.9
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.libspf2.org/spf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libspf2.org/
COMMENT=	Implementation of the Sender Policy Framework

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

CONFLICTS+=	libspf_alt-[0-9]*
CONFLICTS+=	p5-Mail-SPF-[0-9]*

.include "../../mk/bsd.pkg.mk"
