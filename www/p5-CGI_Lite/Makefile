# $NetBSD: Makefile,v 1.3 1999/04/15 20:39:47 tron Exp $
#

DISTNAME=       	CGI_Lite-1.62.pm
PKGNAME=        	p5-CGI_Lite-1.62
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}
EXTRACT_SUFX=		.gz

MAINTAINER=		bad@netbsd.org

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI_Lite/.packlist

NO_WRKSUBDIR=		# defined
EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} > CGI_Lite.pm

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKDIR}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
