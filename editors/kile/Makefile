# $NetBSD: Makefile,v 1.3 2002/12/24 06:09:59 wiz Exp $

DISTNAME=		kile-1.32
CATEGORIES=		editors kde
MASTER_SITES=		http://perso.club-internet.fr/pascal.brachet/kile/

MAINTAINER=		markd@netbsd.org
HOMEPAGE=		http://perso.club-internet.fr/pascal.brachet/kile/index.html
COMMENT=		LaTeX source editor - TeX shell - Gnuplot front end

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

.include "../../graphics/kdegraphics3/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
