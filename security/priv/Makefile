# $NetBSD: Makefile,v 1.9 2004/03/04 02:57:00 simonb Exp $
#

DISTNAME=	priv-1.0-beta2
PKGNAME=	priv-1.0beta2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.thistledown.com.au/pub/simonb/

MAINTAINER=	simonb@NetBSD.org
COMMENT=	Execute commands as a different user

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_PKGINSTALL=	YES

OWN_DIRS=	${PKG_SYSCONFDIR}/priv

.include "../../mk/bsd.pkg.mk"
