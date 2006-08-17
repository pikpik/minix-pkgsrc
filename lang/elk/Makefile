# $NetBSD: Makefile,v 1.34 2006/06/02 16:39:15 joerg Exp $

DISTNAME=	elk-3.99.7
CATEGORIES=	lang
MASTER_SITES=	http://sam.zoy.org/elk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sam.zoy.org/elk/
COMMENT=	Embeddable Scheme interpreter

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		WITH_XAW=${ELK_AWK:Q}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
