# $NetBSD: Makefile,v 1.9 2000/09/09 19:40:21 fredb Exp $
#

DISTNAME=		isakmpd-000915-snap
PKGNAME=		isakmpd-20000915
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.appli.se/pub/isakmpd/

MAINTAINER=		itojun@kame.net

DEPENDS+=		gmp-*:../../devel/gmp

USE_SSL=		yes

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
IGNORE+=		"${PKGNAME} requires ipsec-ready NetBSD"
.endif

ALL_TARGET=		depend all

.include "../../mk/bsd.pkg.mk"
