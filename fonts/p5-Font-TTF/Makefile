# $NetBSD: Makefile,v 1.11 2006/03/04 21:29:39 jlam Exp $
#

DISTNAME=	Font-TTF-0.38.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mhosken/Font-TTF/
COMMENT=	Perl module for TrueType font hacking

WRKSRC=		${WRKDIR}/${DISTNAME:S/.1//}

PERL5_PACKLIST=		auto/Font/TTF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
