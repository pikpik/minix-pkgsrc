# $NetBSD: Makefile,v 1.19 2006/07/27 00:09:06 hubertf Exp $
#

DISTNAME=	hugelatex-2.0
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	# none
DISTFILES=	# nada

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	LaTeX format files with large limits

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# nothing
NO_CHECKSUM=	yes
NO_BUILD=	yes

FILES_SUBST+=	PKG_TEXMFPREFIX=${PKG_TEXMFPREFIX:Q}

CHECK_FILES_SKIP+=	${PKG_TEXMFPREFIX}/web2c/hugelatex.fmt
CHECK_FILES_SKIP+=	${PKG_TEXMFPREFIX}/web2c/hugelatex.log


.include "../../print/teTeX/module.mk"

do-install:
	${LN} -s latex ${PREFIX}/bin/hugelatex

.include "../../mk/bsd.pkg.mk"
