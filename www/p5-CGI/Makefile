# $NetBSD: Makefile,v 1.1 2000/05/11 20:04:03 christos Exp $
#

DISTNAME=       	CGI.pm-2.66
PKGNAME=        	p5-CGI-2.66
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		christos@netbsd.org

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/.packlist

# Our perl packages install their own versions of this perl5 module.
# We need to remove this from our perl installations first.
#
CONFLICTS=		perl-5.*

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
