# $NetBSD: Makefile,v 1.11 2003/10/11 13:40:19 grant Exp $
#

DISTNAME=		rats-2.1
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.securesw.com/rats/

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.securesw.com/rats/
COMMENT=		Rough Auditing Tool for Security

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--datadir=${LOCALBASE}/share/rats
ALL_TARGET=		rats

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
