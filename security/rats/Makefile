# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:40 jlam Exp $
#

DISTNAME=		rats-1.3
CATEGORIES=		security
MASTER_SITES=		http://www.securesw.com/rats/

MAINTAINER=		tech-pkg-ja@jp.netbsd.org
HOMEPAGE=		http://www.securesw.com/rats/
COMMENT=		Rough Auditing Tool for Security

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--libdir=${LOCALBASE}/libdata/rats
ALL_TARGET=		rats

.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
