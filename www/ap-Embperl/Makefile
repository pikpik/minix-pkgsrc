# $NetBSD: Makefile,v 1.4 2001/09/27 23:18:50 jlam Exp $
#

DISTNAME=       HTML-Embperl-1.2.0
PKGNAME=        ap-Embperl-1.2.0
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://perl.apache.org/embperl/
COMMENT=	perl5 library for embedding perl in HTML documents

DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/HTML/Embperl/.packlist

MAKE_ENV+=	APACHE_SRC=${PREFIX}/include/httpd
MAKE_ENV+=	APACHE_MODULES=${PREFIX}/lib/httpd
MAKE_ENV+=	APACHE=${PREFIX}/sbin/httpd

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
