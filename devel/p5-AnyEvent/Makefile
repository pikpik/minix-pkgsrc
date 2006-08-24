# $NetBSD$
#

DISTNAME=	AnyEvent-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.cpan.org/modules/by-authors/Marc_Lehmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/AnyEvent.html
COMMENT=	Simple API for io, timer and completion callbacks

DEPENDS+=	p5-glib2-[0-9]*:../../devel/p5-glib2

PERL5_PACKLIST=	auto/AnyEvent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
