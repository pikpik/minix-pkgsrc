# $NetBSD: Makefile,v 1.4 2003/07/17 21:44:02 grant Exp $
#

DISTNAME=		cl74unix
PKGNAME=		caml-light-0.74
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/lang/caml-light/

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://caml.inria.fr/distrib-caml-light-eng.html
COMMENT=		Another implementation of Caml

WRKSRC=			${WRKDIR}/cl74/src
ALL_TARGET=		world

do-configure:
	(cd ${WRKSRC}; make configure)

post-configure:
	${ECHO} '#define HAS_STRERROR' >> ${WRKDIR}/cl74/config/s.h

.include "../../mk/bsd.pkg.mk"
