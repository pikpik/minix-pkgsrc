# $NetBSD: Makefile,v 1.6 2003/07/21 16:44:36 martti Exp $
#

DISTNAME=	jove4.16.0.63
PKGNAME=	${DISTNAME:S/jove/jove-/}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/hugh/jove-dev/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Small emacs-style editor, but lacks the LISP engine

NO_CONFIGURE=	yes

MAKE_ENV+=	ROOT_GROUP="${ROOT_GROUP}"
MAKE_ENV+=	ROOT_USER="${ROOT_USER}"

.include "../../mk/bsd.pkg.mk"
