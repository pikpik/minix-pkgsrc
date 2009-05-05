# $NetBSD: Makefile,v 1.27 2008/06/15 09:52:00 joerg Exp $

.include "../../devel/scmgit/Makefile.version"

DISTNAME=	# empty
PKGNAME=	scmgit-${GIT_VERSION}
CATEGORIES+=	meta-pkgs devel
DISTFILES=	# empty
MASTER_SITES=	http://www.kernel.org/pub/software/scm/git/

MAINTAINER=	bjs@NetBSD.org
COMMENT=	GIT version control suite meta-package

META_PACKAGE=	yes

DEPENDS+=	scmgit-base>=${GIT_VERSION}:../../devel/scmgit-base
DEPENDS+=	scmgit-docs>=${GIT_VERSION}:../../devel/scmgit-docs

.include "../../mk/bsd.pkg.mk"
