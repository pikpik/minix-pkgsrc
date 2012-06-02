# $NetBSD: Makefile,v 1.16 2012/01/02 04:19:44 dholland Exp $
#

DISTNAME=	splint-3.1.2.src
PKGNAME=	${DISTNAME:S/.src$//}
CATEGORIES=	devel
MASTER_SITES=	http://www.splint.org/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lclint.cs.virginia.edu/
COMMENT=	Statically check C programs

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gmake lex
GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/splint.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
