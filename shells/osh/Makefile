# $NetBSD: Makefile,v 1.8 2004/06/11 10:01:35 cjep Exp $
#

DISTNAME=	osh-041028
CATEGORIES=	shells
MASTER_SITES=	http://jneitzel.sdf1.org/osh/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://jneitzel.sdf1.org/osh/
COMMENT=	Implementation of the UNIX 6th Edition shell

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes
PKG_SHELL=	${PREFIX}/bin/osh

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
