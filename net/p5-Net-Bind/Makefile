# $NetBSD$

DISTNAME=	Net-Bind-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to grovel DNS resolver information

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Bind/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
