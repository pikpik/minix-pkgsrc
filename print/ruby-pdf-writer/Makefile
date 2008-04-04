# $NetBSD$

DISTNAME=	pdf-writer-1.1.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ruby-pdf.rubyforge.org/pdf-writer/
COMMENT=	PDF generation library

DEPENDS+=	${RUBY_PKGPREFIX}-color>=1.4.0:../../graphics/ruby-color
DEPENDS+=	${RUBY_PKGPREFIX}-transaction-simple>=1.3:../../misc/ruby-transaction-simple

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
