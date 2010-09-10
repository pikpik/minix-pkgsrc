# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:25:54 jlam Exp $

DISTNAME=	mongrel_upload_progress-0.2.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/fauna/mongrel
COMMENT=	Mongrel plugin to track file upload status
LICENSE=	# unknown

DEPENDS+=	${RUBY_PKGPREFIX}-mongrel>=0.3.13.3:../../www/mongrel

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
