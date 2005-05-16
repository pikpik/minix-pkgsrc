# $NetBSD$
#

DISTNAME=	cddb.bundle-0.2
PKGNAME=	${DISTNAME:S/./-/}
CATEGORIES=	audio gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gsburn/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gsburn.sourceforge.net/
COMMENT=	CDDB client bundle

WRKSRC=		${WRKDIR}/${DISTNAME:C/-[^-]*$//}
NO_CONFIGURE=	yes
MAKE_ENV+=	ADDITIONAL_CPPFLAGS="-Wno-import"

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
