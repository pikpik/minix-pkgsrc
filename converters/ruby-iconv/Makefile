# $NetBSD: Makefile,v 1.11 2004/11/13 21:28:27 jlam Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-iconv-${RUBY_VERSION}
CATEGORIES=	converters ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Iconv wrapper class for Ruby

RUBY_VERSION_SUPPORTED=	18
USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes
DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
WRKSRC=         	${RUBY_WRKSRC}/ext/iconv
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/iconv

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
