# $NetBSD: Makefile,v 1.3 2001/02/16 14:39:04 wiz Exp $

DISTNAME=       swig1.1p5
PKGNAME=	swig-1.1p5
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.swig.org/pub/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator

DEPENDS+=	python>=2.0:../../lang/python

USE_PERL5=	YES
GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/SWIG1.1p5

.include "../../lang/tcl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
