# $NetBSD: Makefile,v 1.7 2007/08/09 13:29:33 joerg Exp $
#

DISTNAME=		SwishE-0.5
PKGNAME=		${PYPKGPREFIX}-swish-e-0.5
CATEGORIES=		textproc python
MASTER_SITES=		http://jibe.freeshell.org/bits/SwishE/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://jibe.freeshell.org/bits/SwishE/
COMMENT=		Simple Python binding for Swish-E

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../www/swish-e/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
