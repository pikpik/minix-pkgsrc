# $NetBSD: Makefile,v 1.7 2001/03/27 03:20:11 hubertf Exp $

DISTNAME=		libpcap-0.6.1
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		System-independent interface for user-level packet capture

ONLY_FOR_PLATFORM=	SunOS-*-* Linux-*-*	# in NetBSD base system

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=		bison-*:../../devel/bison
BUILD_DEPENDS+=		flex-*:../../devel/flex
.endif

.include "../../mk/bsd.pkg.mk"
