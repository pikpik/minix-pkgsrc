# $NetBSD$
#

DISTNAME=		xcopilot-0.6.6
CATEGORIES=		emulators
MASTER_SITES=		http://xcopilot.cuspy.com/build/

MAINTAINER=		nathanw@netbsd.org
HOMEPAGE=		http://xcopilot.cuspy.com/

DEPENDS+=		xpm-3.4k:../../graphics/xpm

NOT_FOR_ARCHS=		alpha	# suspected LP64 bugs

GNU_CONFIGURE=		yes
USE_X11=		yes

.include "../../mk/bsd.pkg.mk"
