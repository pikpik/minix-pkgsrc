# $NetBSD: Makefile,v 1.33 2007/02/07 19:39:53 drochner Exp $

DISTNAME=	guile-slib-3.1.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	SLIB glue files for guile 1.8

DEPENDS+=	slib>=3.1.2nb1:../../devel/slib

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	share/guile

do-install:
	${LN} -sf ${PREFIX}/share/slib ${PREFIX}/share/guile/site/slib
	${RM} -f ${PREFIX}/share/guile/slibcat
	cd ${PREFIX}/share/guile/site/slib; \
		guile -q -L ${PREFIX}/share/guile/site/slib -l guile.init -c \
			"(require 'new-catalog)"

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
