# $NetBSD: Makefile,v 1.22 2007/10/25 22:00:55 jlam Exp $
#

DISTNAME=	netbsd-doc-print-1.2
PKGREVISION=	1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package including all packages to convert SGML->PDF/PS

DEPENDS+=	tex-jadetex>=2.20nb1:../../print/tex-jadetex
DEPENDS+=	openjade-[0-9]*:../../textproc/openjade
DEPENDS+=	netbsd-doc>=1.2:../../meta-pkgs/netbsd-doc
USE_TOOLS+=	gs:run

META_PACKAGE=	yes

.include "../../textproc/opensp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
