# $NetBSD: Makefile,v 1.1 2003/01/02 04:43:38 explorer Exp $
#

DISTNAME=	frozen-bubble-0.9.3
CATEGORIES=	games
MASTER_SITES=	http://people.mandrakesoft.com/~gc/fb/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	explorer@netbsd.org
HOMEPAGE=	http://www.frozen-bubble.org/
COMMENT=	Pop the frozen bubbles

DEPENDS+=	p5-SDL>=1.19.2:../../devel/p5-SDL

USE_PERL5=	run
USE_GMAKE=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/fb_c_stuff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
