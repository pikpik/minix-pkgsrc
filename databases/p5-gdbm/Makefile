# $NetBSD: Makefile,v 1.10 2001/02/16 14:17:34 wiz Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=		p5-gdbm-1.05
CATEGORIES+=		perl5

MAINTAINER=		packages@netbsd.org
COMMENT=		perl interface to gdbm - GNU database manager

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GDBM_File/.packlist

EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../databases/gdbm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
