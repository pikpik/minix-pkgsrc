# $NetBSD: Makefile,v 1.1.1.1 2002/03/02 02:40:00 rxg Exp $

DISTNAME=	String-ShellQuote-1.00
PKGNAME=	p5-String-ShellQuote-1.00
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://search.cpan.org/search?module=String::ShellQuote
COMMENT=	quote strings for passing through the shell

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/String/ShellQuote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
