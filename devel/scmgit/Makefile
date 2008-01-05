# $NetBSD: Makefile,v 1.23 2007/12/12 04:21:45 bjs Exp $

.include "Makefile.common"

DISTNAME=	scmgit-${GIT_VERSION}
CATEGORIES+=	meta-pkgs

MAINTAINER=	bjs@NetBSD.org
COMMENT=	GIT version control suite meta-package

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base
DEPENDS+=	scmgit-docs-[0-9]*:../../devel/scmgit-docs

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
